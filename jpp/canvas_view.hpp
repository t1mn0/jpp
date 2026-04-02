#pragma once

#include <cstddef>
#include <optional>
#include <stdexcept>

namespace jpp {

template <typename PixelType>
class CanvasView {
  private: // fields:
    PixelType* data_;
    size_t width_, height_, stride_;

  public: // aliases:
    using ValueType = PixelType;
    using ValuePointerType = PixelType*;

  public: // methods:
    /* -~-~-~-~- Constructors: -~-~-~-~- */
    constexpr CanvasView(ValuePointerType data, size_t width, size_t height, size_t stride)
        : data_(data), width_(width), height_(height), stride_(stride) {}

    /* -~-~-~-~- Data access methods: -~-~-~-~- */
    [[nodiscard]] constexpr size_t width() const { return width_; }
    [[nodiscard]] constexpr size_t height() const { return height_; }
    [[nodiscard]] constexpr size_t stride() const { return stride_; }
    [[nodiscard]] constexpr ValuePointerType data() const { return data_; }

    [[nodiscard]] constexpr auto& at(this auto&& self, size_t x, size_t y) {
        if (x >= self.width_ || y >= self.height_) {
            throw std::runtime_error("CanvasView: index out of range");
        }
        return self.data_[y * self.stride_ + x];
    }

    [[nodiscard]] constexpr CanvasView sub_view(size_t x, size_t y, size_t w, size_t h) const {
        return CanvasView(&at(x, y), w, h, stride_);
    }
};

} // namespace jpp
