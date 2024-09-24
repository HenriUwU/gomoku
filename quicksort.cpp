#include <vector>
#include <iostream>
#include <unordered_set>
#include <functional>
#include <utility>

struct pair_hash {
	std::size_t operator() (const std::pair<int, int>& p) const {
		return std::hash<int>{}(p.first) ^ (std::hash<int>{}(p.second) << 1);
	}
};

int partition(std::vector<std::pair<std::pair<int, int>, int>> &vec, int low, int high) {
	int mid = low + (high - low) / 2;

	if (vec[low].second > vec[mid].second) std::swap(vec[low], vec[mid]);
	if (vec[low].second > vec[high].second) std::swap(vec[low], vec[high]);
	if (vec[mid].second > vec[high].second) std::swap(vec[mid], vec[high]);

	std::swap(vec[low], vec[mid]);

	int pivot = vec[low].second;
	int i = low - 1, j = high + 1;

	while (true) {
		do {
			i++;
		} while (vec[i].second < pivot);

		do {
			j--;
		} while (vec[j].second > pivot);

		if (i >= j)
			return j;

		std::swap(vec[i], vec[j]);
	}
}

void quicksort(std::vector<std::pair<std::pair<int, int>, int>> &vec, int low, int high) {
	if (low < high) {
		int pivot = partition(vec, low, high);

		quicksort(vec, low, pivot);
		quicksort(vec, pivot + 1, high);
	}
}

int main() {
	std::unordered_set<std::pair<int, int>, pair_hash> set;

	set.insert({7, 8});
	set.insert({1, 2});
	set.insert({5, 6});
	set.insert({3, 4});

	std::vector<int> values = {50, 80, 90, 40};
	std::vector<std::pair<std::pair<int, int>, int>> vec;

	int index = 0;
	for (const auto& elem : set) {
		vec.push_back({elem, values[index]});
		index++;
	}

	std::cout << "Before quicksort :" << std::endl;
	for (const auto& elem : vec) {
		std::cout << "((" << elem.first.first << ", " << elem.first.second << "), " << elem.second << ")\n";
	}

	quicksort(vec, 0, vec.size() - 1);

	std::cout << "After quicksort :" << std::endl;
	for (const auto& elem : vec) {
		std::cout << "((" << elem.first.first << ", " << elem.first.second << "), " << elem.second << ")\n";
	}

	return 0;
}
