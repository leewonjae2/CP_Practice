#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <set>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;
		size_t mapSize = std::min(keys.size(), values.size());

		for (size_t i = 0; i < mapSize; i++)
		{
			m.insert(std::pair<K, V>(keys[i], values[i]));
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;
		v.reserve(m.size());

		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			v.push_back(iter->first);
		}

		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;

		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			v.push_back(iter->second);
		}

		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{

		std::vector<T> rv;
		if (v.size() == 0)
		{
			return rv;
		}
		rv.reserve(v.size());
		for (size_t i = 1; i < v.size(); i++)
		{
			rv.push_back(v[v.size() - i]);
		}

		rv.push_back(v[0]);

		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;
		std::set<T> s;


		for (size_t i = 0; i < v1.size(); i++)
		{

			if (s.insert(v1[i]).second == true)
			{
				combined.push_back(v1[i]);
			}
		}

		for (size_t i = 0; i < v2.size(); i++)
		{
			if ((s.insert(v2[i])).second == true)
			{
				combined.push_back(v2[i]);
			}
		}

		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;

		for (auto iter = m1.begin(); iter != m1.end(); iter++)
		{
			combined.insert(std::pair<K, V>(iter->first, iter->second));
		}

		for (auto iter = m2.begin(); iter != m2.end(); iter++)
		{
			combined.insert(std::pair<K, V>(iter->first, iter->second));
		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		if (v.size() == 0)
		{
			return os;
		}

		for (size_t i = 0; i < v.size() - 1; i++)
		{
			os << v[i] << ", ";
		}

		os << v[v.size() - 1];

		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		if (m.size() == 0)
		{
			return os;
		}

		for (auto iter = m.begin(); iter != m.end(); iter++)
		{
			os << "{ " << iter->first << ", " << iter->second << " }" << std::endl;
		}

		return os;
	}
}