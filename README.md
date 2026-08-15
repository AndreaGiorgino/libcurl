# libcurl

 Cpp23 static library to make http requests

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
using namespace libcurl;

auto main(int, char**) -> int {

    ...

    return 0;
}
```

> Look at [example](example) for more
