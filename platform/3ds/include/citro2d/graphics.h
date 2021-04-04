#pragma once

#include "modules/graphics/graphics.h"
#include "citro2d/citro.h"

#define RENDERER_NAME    "citro3d"
#define RENDERER_VERSION "1.6.2"
#define RENDERER_VENDOR  "devkitPro"
#define RENDERER_DEVICE  "DMP PICA200"

#define SCREEN_TOP_WIDTH 400
#define SCREEN_BOT_WIDTH 320
#define SCREEN_HEIGHT    240

enum class love::Graphics::Screen : uint8_t
{
    SCREEN_LEFT,
    SCREEN_RIGHT,
    SCREEN_BOTTOM,
    SCREEN_MAX_ENUM
};

namespace love::citro2d
{
    class Graphics : public love::Graphics
    {
        public:
            Graphics();

            Screen GetActiveScreen() const override;

            std::vector<std::string> GetScreens() const override;

            const int GetWidth(Screen screen) const override;

            const int GetHeight() const override;

            void SetActiveScreen(Screen screen) override;

            RendererInfo GetRendererInfo() const override;

            void Clear(std::optional<Colorf> color, std::optional<int> stencil, std::optional<double> depth) override;

            void Present() override;

            void SetColor(Colorf color) override;

            Font * NewDefaultFont(int size, const Texture::Filter & filter) override;

            Font * NewFont(const Rasterizer & rasterizer, const Texture::Filter & filter = Texture::defaultFilter) override;

            /* Primitives */

            void Polygon(DrawMode mode, const Vector2 * points, size_t count) override;

            void Polyfill(const Vector2 * points, size_t count, u32 color, float depth);

            void Polyline(const Vector2 * points, size_t count);

            void Rectangle(DrawMode mode, float x, float y, float width, float height) override;

            void Rectangle(DrawMode mode, float x, float y, float width, float height, float rx, float ry) override {};

            void Rectangle(DrawMode mode, float x, float y, float width, float height, float rx, float ry, int points) override {};

            void Ellipse(DrawMode mode, float x, float y, float a, float b) override;

            void Ellipse(DrawMode mode, float x, float y, float a, float b, int points) override {};

            void Circle(DrawMode mode, float x, float y, float radius) override;

            void Circle(DrawMode mode, float x, float y, float radius, int points) override {};

            void Arc(DrawMode drawmode, ArcMode arcmode, float x, float y, float radius, float angle1, float angle2);

            void Arc(DrawMode drawmode, ArcMode arcmode, float x, float y, float radius, float angle1, float angle2, int points) {};

            void Points(const Vector2 * points, size_t count, const Colorf * colors, size_t colorCount) override {};

            void SetPointSize(float size) override {};

            void Line(const Vector2 * points, int count) override;

            /* End Primitives */

            void SetLineWidth(float width) override;

            void SetDefaultFilter(const Texture::Filter & filter);

            void SetScissor(const Rect & scissor) override;

            void SetScissor() override;

            /* Nintendo 3DS */

            void Set3D(bool enable);

            /* End Nintendo 3DS */

            /* Useless */

            void SetBlendMode(BlendMode mode, BlendAlpha alpha) override {};

            void SetColorMask(ColorMask mask) override {};

            static constexpr int MAX_2D_SCREENS = 2;

            static StringMap<Screen, MAX_2D_SCREENS>::Entry plainScreenEntries[];
            static StringMap<Screen, MAX_2D_SCREENS> plainScreens;

            static bool GetConstant(const char * in, Screen & out);
            static bool GetConstant(Screen in, const char *& out);
            static std::vector<std::string> GetConstants(Screen);
    };
}
