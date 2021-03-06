#ifndef _DRIVER_DISPLAY_H_
#define _DRIVER_DISPLAY_H_
#include <stdint.h>
#include "pins.h"

#define OLED_SPI         SPI1
#define OLED_SPI_CLK     RCC_APB2Periph_SPI1

#define ENABLE_2V8       (&PIN_PB3)

#define OLED_NCS         (&PIN_PA4)
#define OLED_A0          (&PIN_PC0)
#define OLED_RESET       (&PIN_PC7)

#define OLED_VEN         (&PIN_PC1)

#define OLED_SPI_SCK     (&PIN_PA5)
#define OLED_SPI_MOSI    (&PIN_PA7)


void oled_init();
void oled_draw(uint8_t x, uint8_t y, void* p_sprite);
void oled_power(uint8_t level);
void oled_setwindow(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1);
void oled_push(uint16_t pixel, uint16_t count);


class Arduino_GFX {
  public:
    void constructor();
    virtual void drawPixel(int16_t x, int16_t y, uint16_t color);
    virtual void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
    virtual void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
    virtual void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    virtual void fillScreen(uint16_t color);
  
    void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
    void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    void drawCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, uint16_t color);
    void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t cornername, int16_t delta, uint16_t color);
  
    void drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
    void fillTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color);
    void drawRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
    void fillRoundRect(int16_t x0, int16_t y0, int16_t w, int16_t h, int16_t radius, uint16_t color);
  
    void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, int16_t w, int16_t h, uint16_t color);
    void drawChar(int16_t x, int16_t y, unsigned char c, uint16_t color, uint16_t bg, uint8_t size);
  
    uint32_t write(uint8_t);

    void print(char *str);
    void println(char *str);
    
    void setCursor(int16_t x, int16_t y);
    void setTextColor(uint16_t c);
    void setTextColor(uint16_t c, uint16_t bg);
    void setTextSize(uint8_t s);
    void setTextWrap(bool w);
  
    int16_t height(void);
    int16_t width(void);
    
    
 protected:
    int16_t  WIDTH, HEIGHT;   // this is the 'raw' display w/h - never changes
    int16_t  _width, _height; // dependent on rotation
    int16_t  cursor_x, cursor_y;
    uint16_t textcolor, textbgcolor;
    uint8_t  textsize;
    bool  wrap; // If set, 'wrap' text at right edge of display
};

class Arduino_OLED : public Arduino_GFX {
  public:
    Arduino_OLED();

    void     begin(),
             setAddrWindow(uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1),
             pushColor(uint16_t color),
             fillScreen(uint16_t color),
             drawPixel(int16_t x, int16_t y, uint16_t color),
             drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color),
             drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color),
             fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    uint16_t Color565(uint8_t r, uint8_t g, uint8_t b);

  private:
};

extern Arduino_OLED OLED;

#endif
