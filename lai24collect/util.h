/* Copyright (C) 2015-2018 IAPRAS - All Rights Reserved */

#pragma once

#include "stdafx.h"

// trim from start (in place)
static inline void ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
		return !std::isspace(ch);
	}));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
	}).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
	ltrim(s);
	rtrim(s);
}

// trim from start (copying)
static inline std::string ltrim_copy(std::string s) {
	ltrim(s);
	return s;
}

// trim from end (copying)
static inline std::string rtrim_copy(std::string s) {
	rtrim(s);
	return s;
}

// trim from both ends (copying)
static inline std::string trim_copy(std::string s) {
	trim(s);
	return s;
}

template<typename T>
inline T sqr(const T &t) {return t*t;}


template<typename T>
inline T cube(const T &t) {return t*t*t;}

template<typename T>
std::string to_string(const T &t)
{
    std::ostringstream oss;
    oss << t;
    return oss.str();
}

static inline std::wstring string_to_wstring(const std::string& s) {
	std::wstring ws;
	ws.assign(s.begin(), s.end());
	return ws;
}