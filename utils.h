#pragma once

#define NO_COPY(T) T(const T&) = delete; void operator=(const T&) = delete

#define NO_MOVE(T) T(T&&) = delete; void operator=(T&&) = delete