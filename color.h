#ifndef color_h
#define color_h

#include "vec3.h"
#include "interval.h"

using color = vec3;

inline double linear_to_gamma(double linear_component) {
    if (linear_component > 0) {
        return sqrt(linear_component);
    }
    return 0;
}

std::string write_color(const color& pixel_color) {
    auto r = linear_to_gamma(pixel_color.x());
    auto g = linear_to_gamma(pixel_color.y());
    auto b = linear_to_gamma(pixel_color.z());

    // Translate the [0,1] component values to the byte range [0,255].
    static const interval intensity(0.000, 0.999);
    int rbyte = int(256 * intensity.clamp(r));
    int gbyte = int(256 * intensity.clamp(g));
    int bbyte = int(256 * intensity.clamp(b));

    // Write out the pixel color components.
    //out << rbyte << ' ' << gbyte << ' ' << bbyte << '\n';
    return (std::to_string(rbyte) + ' ' + std::to_string(gbyte) + ' ' + std::to_string(bbyte));
}

#endif
