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
