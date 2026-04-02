#pragma once

#include "../canvas_view.hpp"
#include "../color.hpp"

namespace jpp {

template <typename PixelType> requires std::convertible_to<Color, PixelType>
void fill(CanvasView<PixelType>& canvas, Color color) {
    for (size_t y = 0; y < canvas.height(); ++y) {
        for (size_t x = 0; x < canvas.width(); ++x) {
            canvas.at(x, y) = color;
        }
    }
}

} // namespace jpp
