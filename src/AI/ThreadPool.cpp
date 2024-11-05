/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsebille <hsebille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:23:02 by hsebille          #+#    #+#             */
/*   Updated: 2024/10/16 22:51:02 by hsebille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AI/ThreadPool.hpp"

ThreadPool::ThreadPool(size_t nbThreads) : activeTasks(0), stop(false) {
	for (size_t i = 0; i < nbThreads; i++) {
		workers.emplace_back([this] {
			while (true) {
				std::function<void()> task;
				{
					std::unique_lock<std::mutex> lock(this->queueMutex);
					this->condition.wait(lock, [this] { return this->stop || !this->tasks.empty(); });

					if (this->stop && this->tasks.empty())
						return ;
					
					task = std::move(this->tasks.front());
					this->tasks.pop();
					++activeTasks;
				}
				task();

				{
					std::unique_lock<std::mutex> lock(this->queueMutex);
					--activeTasks;
					if (tasks.empty() && activeTasks == 0)
						doneCondition.notify_all();
				}
			}
		});
	}
}

ThreadPool::~ThreadPool() {
	{
		std::unique_lock<std::mutex> lock(queueMutex);
		stop = true;
	}
	condition.notify_all();
	for (std::thread &worker : workers)
		worker.join();
}

void ThreadPool::waitForAll() {
	std::unique_lock<std::mutex> lock(queueMutex);
	doneCondition.wait(lock, [this] { return tasks.empty() && activeTasks == 0; });
}