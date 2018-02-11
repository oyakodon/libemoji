#ifndef SRC_EG_LINE_BOX_H_
#define SRC_EG_LINE_BOX_H_

#include <string>

#include "SkCanvas.h"
#include "SkColor.h"
#include "SkRect.h"
#include "SkScalar.h"
#include "SkTypeface.h"

/**
 * 行ボックス
 */
class EgLine final {
public:
    struct MeasureSpec {
        SkScalar fTextSize;
        SkScalar fTextScaleX;
        SkRect fBounds;
    };

    EgLine(
        const std::string& text,
        SkScalar width,
        SkScalar lineHeight,
        sk_sp<SkTypeface> typeface
    );

    void setTextAlign(SkPaint::Align textAlign) { fTextAlign = textAlign; }
    void setColor(SkColor color) { fColor = color; }

    MeasureSpec measure();
    void draw(SkCanvas* canvas, int y, MeasureSpec spec);

private:

    std::string fText;
    SkScalar fWidth;
    SkScalar fLineHeight;
    SkPaint::Align fTextAlign;
    sk_sp<SkTypeface> fTypeface;
    SkColor fColor;
};

#endif