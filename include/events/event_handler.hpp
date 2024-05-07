#pragma once
#include <functional>

template <typename PayloadType>
using EventHandler = std::function<void(T&)>;