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

#pragma once

#include "gomoku.hpp"

class ThreadPool {
	private:
		std::queue<std::function<void()>>	tasks;
		std::vector<std::thread>			workers;
		std::mutex							queueMutex;
		std::condition_variable				condition;
		std::condition_variable				doneCondition;
		int									activeTasks;
		bool								stop;

	public:
		ThreadPool(size_t nbThreads);
		~ThreadPool();

		template<class F>
		void enqueue(F&& f) {
			{
				std::unique_lock<std::mutex> lock(queueMutex);
				tasks.emplace(std::forward<F>(f));
			}
			condition.notify_one();
		}

		void waitForAll();
};