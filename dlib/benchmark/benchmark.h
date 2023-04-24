#ifndef BENCHMArK_H_
#define BENCHMArK_H_


#include "benchmark_abstract.h"

/// <summary>
/// Set the start point of the benchmark clock
/// </summary>
namespace dlib {
    class benchmark;
    constexpr long double c_msfactor = 1000.0;
    constexpr long double c_secFactor = 1000.0 * c_msfactor;

    typedef std::chrono::_V2::system_clock::time_point time_point_t;
    typedef long double us_t;
    typedef long double ms_t;
    typedef long double sec_t;

    class benchmark {
        public:

            void start() {
                m_startTime = std::chrono::high_resolution_clock::now();
            }

            /// <summary>
            /// Set the end point of the benchmark clock
            /// and calculate the ellapsed milliseconds
            /// </summary>
            /// <returns>ellapsed milliseconds</returns>
            void end() {
                m_endTime = std::chrono::high_resolution_clock::now();

                m_ellapsedTime = (us_t) std::chrono::duration_cast<std::chrono::microseconds>(
                        m_endTime - m_startTime).count();
            }

            /// <summary>
            /// Get the ellapsed microseconds
            /// </summary>
            /// <returns>ellapsed microseconds</returns>
            us_t get_us() {
                return m_ellapsedTime;
            }

            /// Get the ellapsed milliseconds
            /// </summary>
            /// <returns>ellapsed milliseconds</returns>
            ms_t get_ms() {
                return m_ellapsedTime / c_msfactor;
            }

            /// <summary>
            /// Get the ellapsed seconds
            /// </summary>
            /// <returns>ellapsed seconds</returns>
            sec_t get_sec() {
                return m_ellapsedTime / c_secFactor;
            }

        private:
            time_point_t m_startTime;
            time_point_t m_endTime;
            us_t m_ellapsedTime;
    };
}
#endif