//#pragma once
//#include <chrono>

#undef DLIB_BENCHMARK_ABSTRACT_H_
#ifdef DLIB_BENCHMARK_ABSTRACT_H_

#include <chrono>

/// <summary>
/// Class for benchmarking
/// </summary>
namespace dlib {
    constexpr long double c_msfactor = 1000.0;
    constexpr long double c_secFactor = 1000.0 * c_msfactor;

    typedef std::chrono::_V2::system_clock::time_point time_point_t;
    typedef long double us_t;
    typedef long double ms_t;
    typedef long double sec_t;
    class benchmark {
        public:
            /// <summary>
            /// Set the start point of the benchmark clock
            /// </summary>
            void start();

            /// <summary>
            /// Set the end point of the benchmark clock
            /// and calculate the ellapsed milliseconds
            /// </summary>
            /// <returns>ellapsed milliseconds</returns>
            void end();

            /// <summary>
            /// Get the ellapsed microseconds
            /// </summary>
            /// <returns>ellapsed microseconds</returns>
            us_t get_us();

            /// <summary>
            /// Get the ellapsed milliseconds
            /// </summary>
            /// <returns>ellapsed milliseconds</returns>
            ms_t get_ms();

            /// <summary>
            /// Get the ellapsed seconds
            /// </summary>
            /// <returns>ellapsed seconds</returns>
            sec_t get_sec();

        private:
            time_point_t m_startTime;
            time_point_t m_endTime;
            us_t m_ellapsedTime;

    };
}
#endif