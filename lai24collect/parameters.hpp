/* Copyright (C) 2015-2018 IAPRAS - All Rights Reserved */

#pragma once

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <map>

#include "util.h"


struct ParametersRegister {

    struct Initializer {
        Initializer(const std::string &title, std::string &v) {
            pr.strings.insert(std::pair<std::string, std::string&>(title, v));
        }
        Initializer(const std::string &title, double &v) {
            pr.doubles.insert(std::pair<std::string, double&>(title, v));
        }
        Initializer(const std::string &title, int &v) {
            pr.ints.insert(std::pair<std::string, int&>(title, v));
        }
        Initializer(const std::string &title, unsigned &v) {
            pr.uints.insert(std::pair<std::string, unsigned&>(title, v));
        }
        // Initializer(const std::string &title, size_t &v) {
        //     pr.sizes.insert(std::pair<std::string, size_t&>(title, v));
        // }
        Initializer(const std::string &title, bool &v) {
            pr.bools.insert(std::pair<std::string, bool&>(title, v));
        }
    };

    // alternative implementation
    /*
    template<typename T>
    void register_parameter(ParametersRegister &p, const std::string &title, const T &v) {}

    template<int>
    void register_parameter(ParametersRegister &p, const std::string &title, int &v) {
        std::cout << "Register int " << title << std::endl;
        p.ints.insert(std::pair<std::string, int&>(title, v));
    }

    template<bool>
    void register_parameter(ParametersRegister &p, const std::string &title, bool &v) {
        std::cout << "Register int " << title << std::endl;
        p.ints.insert(std::pair<std::string, bool&>(title, v));
    }

    template<double>
    void register_parameter(ParametersRegister &p, const std::string &title, double &v) {
        std::cout << "Register int " << title << std::endl;
        p.ints.insert(std::pair<std::string, double&>(title, v));
    }

    template<std::string>
    void register_parameter(ParametersRegister &p, const std::string &title, std::string &v) {
        std::cout << "Register int " << title << std::endl;
        p.ints.insert(std::pair<std::string, std::string&>(title, v));
    }
    */

    ParametersRegister() = default;

    void parse(const char *parameters_file_name) {
        /*
        for (auto t: pr.strings) {
            std::cerr << "strings " << t.first << std::endl;
        }
        for (auto t: pr.doubles) {
            std::cerr << "doubles " << t.first << std::endl;
        }
        for (auto t: pr.ints) {
            std::cerr << "ints " << t.first << std::endl;
        }
        */

        std::string line;
        line.reserve(1024);
        std::ifstream f(parameters_file_name);
        if (not f.is_open()) {
            std::cerr << "No config file " << parameters_file_name << " found" << std::endl;
            return;
        }
        int line_n = 0;
        while (not f.eof()) {
            getline(f, line);
            ++line_n;
            trim(line);
            if (line.empty() or line[0] == '#') {
                continue;
            }
            std::istringstream ls(line);
            std::string k, v;
            getline(ls, k, '=');
            getline(ls, v, '=');
            trim(k);
            trim(v);
            
            {
                auto p = pr.strings.find(k);
                if (p != pr.strings.end()) {
                    p->second = v;
                    continue;
                }
            }
            {
                auto p = pr.doubles.find(k);
                if (p != pr.doubles.end()) {
                    double vv;
                    std::istringstream(v) >> vv;
                    p->second = vv;
                    continue;
                }
            }
            {
                auto p = pr.ints.find(k);
                if (p != pr.ints.end()) {
                    int vv;
                    std::istringstream(v) >> vv;
                    p->second = vv;
                    continue;
                }
            }
            {
                auto p = pr.uints.find(k);
                if (p != pr.uints.end()) {
                    unsigned vv;
                    std::istringstream(v) >> vv;
                    p->second = vv;
                    continue;
                }
            }
            {
                auto p = pr.sizes.find(k);
                if (p != pr.sizes.end()) {
                    size_t vv;
                    std::istringstream(v) >> vv;
                    p->second = vv;
                    continue;
                }
            }
            {
                auto p = pr.bools.find(k);
                if (p != pr.bools.end()) {
                    bool vv;
					std::string t;
                    std::istringstream(v) >> t;
					vv = (t == "1" || t == "true");
                    p->second = vv;
                    continue;
                }
            }
            std::cerr << "Unknown parameter " << k << std::endl;
        }
        f.close();
    }

private:
    static ParametersRegister pr;

    std::map<std::string, std::string&> strings;
    std::map<std::string, double&> doubles;
    std::map<std::string, int&> ints;
    std::map<std::string, unsigned&> uints;
    std::map<std::string, size_t&> sizes;
    std::map<std::string, bool&> bools;
};

#define PARAMETER(T, N, V) public: T N = V; private: Initializer N##_i = Initializer(#N, N)

// alternative implementation

/*
template<typename T>
class Parameter
{
    T v;
public:
    Parameter(const std::string &title, const T &def_v): v(def_v) {
        ParametersRegister::pr.register_parameter(title, v);
    }

    T& operator T() {return v;}

    void parse(const std::string &s) {
        std::istringstream(s) >> v;
    }
};

template<>
class Parameter<std::string>
{
    std::string v;
public:
    Parameter(const std::string &title, std::string def_v): v(std::move(def_v)) {
        ParametersRegister::pr.register_parameter(title, v);
    }

    std::string& explicit operator std::string() {return v;}

    void parse(const std::string &s) {
        v = s;
    }
};
 */

/*
struct Parameters: public ParametersRegister {
    Parameter<std::string> s = Parameter<std::string>("s", "def");
    Parameter<double> a = Parameter<double>("a", 666);
    Parameter<double> b = Parameter<double>("b", 666);
    Parameter<double> t = Parameter<double>("t", 666);
    Parameter<int> n = Parameter<int>("n", 666);
};
 */
