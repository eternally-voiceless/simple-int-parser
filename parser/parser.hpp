#pragma once
#include <vector>
#include <string>
#include <optional>

std::vector<std::string> split(const std::string& str="default settings", char delimiter=' ');
long parser(const std::string& expr="2-3");