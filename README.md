# libcurl

[curl](https://curl.se) interface library in Cpp23

> [!IMPORTANT]
> Since this library is still in development, it may not work correctly or some
> functionalities might be missing

## Build

### Requirements

- [CMake](https://cmake.org/)

### Compilation

```bash
git clone https://github.com/giorgi.page/libcurl
cd libcurl

./build.sh
```

### Debug

```bash
cmake -B build -DDEBUG=ON \
    && cmake --build build --parallel $(($(nproc) - 1))
```

### Testing

```bash
cmake -B build \
    -DCURL_BUILD_TESTING=ON \
    && cmake --build build --parallel $(($(nproc) - 1)) \
    && ctest --test-dir build 
```

### Example

```bash
cmake -B build \
    -DCURL_BUILD_EXAMPLE=ON \
    && cmake --build build --parallel $(($(nproc) - 1))

./build/example/example
```


## Usage

```cpp
#include <iostream>
#include <libcurl/curl.hxx>

using libcurl::request;
using std::chrono_literals::operator ""ms;

#define ANSI_CLEAR_LINE  "\033[2K"

auto main(int, char**) -> int {
    // create the request
    const request req {"https://httpbun.com/delay/5"};

    // get the response future
    auto future {libcurl::curl(req)};

    // non-blocking
    std::size_t dots {};
    while (future.wait_for(250ms) != std::future_status::ready) {
        std::cout << "\r" ANSI_CLEAR_LINE "Fetching" << std::string(dots++ % 4, '.');
        std::cout.flush();
    }

    // blocking
    // future.wait();

    // get the response
    const auto res {future.get()};

    std::cout << "\r" "Status code: "
              << libcurl::getStatusCodeName(res.getStatusCode()) << std::endl;

    return 0;
}
```

> Source at [example](example)
