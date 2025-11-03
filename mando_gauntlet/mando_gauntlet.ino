/*
 * Mandalorian Gauntlet Display Animations
 * Waveshare 0.96" OLED Display (128x64)
 * SSD1306 Controller
 * 
 * Required Library: U8g2 (install via Arduino Library Manager)
 * 
 * Wiring (I2C Mode - for Arduino Uno/Nano):
 * VCC -> 5V (or 3.3V)
 * GND -> GND
 * SCL -> A5
 * SDA -> A4
 */

#include <U8g2lib.h>
#include <Wire.h>

// Initialize display for I2C (0.96" 128x64 SSD1306)
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

int frame = 0;
int animationMode = 0;
unsigned long lastModeChange = 0;
int chargeLevel = 0;
bool chargingUp = true;

void setup() {
  u8g2.begin();
  u8g2.setContrast(255);
}

void loop() {
  u8g2.clearBuffer();
  
  // Cycle through different gauntlet animations every 5 seconds
  if(millis() - lastModeChange > 5000) {
    animationMode = (animationMode + 1) % 9;
    lastModeChange = millis();
    chargeLevel = 0;
    chargingUp = true;
  }
  
  switch(animationMode) {
    case 0:
      drawChainCode();
      break;
    case 1:
      drawWristRocket();
      break;
    case 2:
      drawFlamethrower();
      break;
    case 3:
      drawGrappleHook();
      break;
    case 4:
      drawShieldGenerator();
      break;
    case 5:
      drawTargetingSystem();
      break;
    case 6:
      drawPowerStatus();
      break;
    case 7:
      drawMandalorianText1();
      break;
    case 8:
      drawMandalorianText2();
      break;
  }
  
  u8g2.sendBuffer();
  frame++;
  delay(50);
}

// Chain Code Display
void drawChainCode() {
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(35, 10, "CHAIN CODE");
  
  // Draw barcode-style chain code pattern
  int startX = 20;
  int startY = 20;
  int barWidth = 3;
  
  // Pattern of bars (like a barcode/chain code)
  int pattern[] = {1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1};
  
  for(int i = 0; i < 22; i++) {
    if(pattern[i] == 1) {
      u8g2.drawBox(startX + i * (barWidth + 1), startY, barWidth, 18);
    }
  }
  
  // Animated scan line
  int scanY = startY + ((frame / 2) % 18);
  u8g2.drawLine(startX - 2, scanY, startX + 90, scanY);
  
  // Chain code number display
  u8g2.setFont(u8g2_font_7x13_tr);
  u8g2.drawStr(15, 52, "CC-2187-9402");
  
  // Additional info
  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.drawStr(10, 63, "VERIFIED");
  
  // Mythosaur skull icon (more detailed)
  int skullX = 108;
  int skullY = 56;
  
  // Main skull shape - wide and angular
  u8g2.drawLine(skullX - 6, skullY - 4, skullX - 4, skullY - 6); // Left top
  u8g2.drawLine(skullX - 4, skullY - 6, skullX + 4, skullY - 6); // Top
  u8g2.drawLine(skullX + 4, skullY - 6, skullX + 6, skullY - 4); // Right top
  u8g2.drawLine(skullX + 6, skullY - 4, skullX + 6, skullY - 1); // Right side
  u8g2.drawLine(skullX - 6, skullY - 4, skullX - 6, skullY - 1); // Left side
  
  // Wide jaw/cheek bones
  u8g2.drawLine(skullX - 6, skullY - 1, skullX - 7, skullY + 1); // Left cheek
  u8g2.drawLine(skullX + 6, skullY - 1, skullX + 7, skullY + 1); // Right cheek
  
  // Bottom jaw sections (angular)
  u8g2.drawLine(skullX - 7, skullY + 1, skullX - 5, skullY + 3);
  u8g2.drawLine(skullX - 5, skullY + 3, skullX - 2, skullY + 4);
  u8g2.drawLine(skullX + 7, skullY + 1, skullX + 5, skullY + 3);
  u8g2.drawLine(skullX + 5, skullY + 3, skullX + 2, skullY + 4);
  
  // Chin/center jaw
  u8g2.drawLine(skullX - 2, skullY + 4, skullX, skullY + 5);
  u8g2.drawLine(skullX + 2, skullY + 4, skullX, skullY + 5);
  
  // Eye sockets - angular and menacing
  u8g2.drawBox(skullX - 4, skullY - 4, 2, 3);
  u8g2.drawBox(skullX + 2, skullY - 4, 2, 3);
  
  // Nose cavity (inverted triangle)
  u8g2.drawPixel(skullX, skullY - 2);
  u8g2.drawLine(skullX - 1, skullY, skullX + 1, skullY);
  
  // Horns/tusks extending from sides
  u8g2.drawLine(skullX - 7, skullY + 1, skullX - 8, skullY + 2);
  u8g2.drawLine(skullX + 7, skullY + 1, skullX + 8, skullY + 2);
}

// Wrist Rocket Launcher
void drawWristRocket() {
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(25, 10, "WRIST ROCKET");
  
  // Missile silhouette - more tactical/military style
  int rocketX = 64;
  int rocketY = 32;
  
  // Missile body (cylindrical)
  u8g2.drawBox(rocketX - 2, rocketY - 10, 4, 20);
  
  // Nose cone
  u8g2.drawLine(rocketX - 2, rocketY - 10, rocketX, rocketY - 14);
  u8g2.drawLine(rocketX + 2, rocketY - 10, rocketX, rocketY - 14);
  u8g2.drawLine(rocketX - 1, rocketY - 10, rocketX, rocketY - 13);
  u8g2.drawLine(rocketX + 1, rocketY - 10, rocketX, rocketY - 13);
  
  // Tail fins (angular)
  u8g2.drawLine(rocketX - 2, rocketY + 6, rocketX - 5, rocketY + 10);
  u8g2.drawLine(rocketX - 5, rocketY + 10, rocketX - 2, rocketY + 10);
  u8g2.drawLine(rocketX + 2, rocketY + 6, rocketX + 5, rocketY + 10);
  u8g2.drawLine(rocketX + 5, rocketY + 10, rocketX + 2, rocketY + 10);
  
  // Warhead bands
  u8g2.drawLine(rocketX - 2, rocketY - 6, rocketX + 2, rocketY - 6);
  u8g2.drawLine(rocketX - 2, rocketY - 3, rocketX + 2, rocketY - 3);
  
  // Targeting brackets around missile
  u8g2.drawLine(rocketX - 12, rocketY - 15, rocketX - 8, rocketY - 15);
  u8g2.drawLine(rocketX - 12, rocketY - 15, rocketX - 12, rocketY - 11);
  u8g2.drawLine(rocketX + 12, rocketY - 15, rocketX + 8, rocketY - 15);
  u8g2.drawLine(rocketX + 12, rocketY - 15, rocketX + 12, rocketY - 11);
  u8g2.drawLine(rocketX - 12, rocketY + 15, rocketX - 8, rocketY + 15);
  u8g2.drawLine(rocketX - 12, rocketY + 15, rocketX - 12, rocketY + 11);
  u8g2.drawLine(rocketX + 12, rocketY + 15, rocketX + 8, rocketY + 15);
  u8g2.drawLine(rocketX + 12, rocketY + 15, rocketX + 12, rocketY + 11);
  
  // Ammo count
  u8g2.setFont(u8g2_font_9x15_tr);
  u8g2.drawStr(45, 55, "AMMO: 4");
  
  // Status
  u8g2.setFont(u8g2_font_5x7_tr);
  if((frame / 10) % 2 == 0) {
    u8g2.drawStr(40, 63, "[ARMED]");
  }
}

// Flamethrower
void drawFlamethrower() {
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(20, 10, "FLAMETHROWER");
  
  // Fuel gauge
  int fuelLevel = 100 - ((frame * 2) % 100);
  u8g2.drawFrame(20, 20, 88, 12);
  u8g2.drawBox(22, 22, (fuelLevel * 84) / 100, 8);
  
  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.drawStr(32, 29, "FUEL");
  
  // Flame effect
  int flameY = 40;
  for(int i = 0; i < 5; i++) {
    int flameSize = random(8, 16);
    int flameX = 30 + i * 15 + random(-3, 3);
    
    // Flame shape
    u8g2.drawTriangle(
      flameX, flameY,
      flameX - flameSize/2, flameY + flameSize,
      flameX + flameSize/2, flameY + flameSize
    );
  }
  
  // Temperature
  u8g2.setFont(u8g2_font_6x10_tr);
  char temp[15];
  sprintf(temp, "TEMP: %d C", 800 + (frame % 200));
  u8g2.drawStr(20, 63, temp);
}

// Grappling Hook
void drawGrappleHook() {
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(15, 10, "GRAPPLING HOOK");
  
  // Hook launching animation
  int hookY = 20 + (frame % 30);
  
  // Cable
  for(int y = 20; y < hookY; y += 2) {
    u8g2.drawPixel(64, y);
  }
  
  // Hook
  u8g2.drawCircle(64, hookY, 4);
  u8g2.drawLine(60, hookY, 64, hookY - 4);
  u8g2.drawLine(68, hookY, 64, hookY - 4);
  
  // Distance readout
  u8g2.setFont(u8g2_font_7x13_tr);
  char dist[15];
  sprintf(dist, "RANGE: %dm", (frame % 30) + 5);
  u8g2.drawStr(25, 55, dist);
  
  // Cable strength
  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.drawStr(15, 63, "TENSILE: 500kg");
}

// Shield Generator
void drawShieldGenerator() {
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(10, 10, "SHIELD GENERATOR");
  
  // Pulsing shield effect
  int centerX = 64;
  int centerY = 35;
  int pulseSize = 15 + (frame % 10);
  
  // Multiple shield rings
  for(int r = pulseSize; r < pulseSize + 15; r += 5) {
    if((frame + r) % 10 < 5) {
      u8g2.drawCircle(centerX, centerY, r);
    }
  }
  
  // Center point (gauntlet)
  u8g2.drawBox(centerX - 3, centerY - 5, 6, 10);
  
  // Shield strength bar
  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.drawStr(35, 55, "STRENGTH");
  
  int shieldStr = 100 - ((frame / 2) % 100);
  u8g2.drawFrame(25, 47, 78, 6);
  u8g2.drawBox(26, 48, (shieldStr * 76) / 100, 4);
  
  // Status
  if(shieldStr > 50) {
    u8g2.drawStr(40, 63, "ACTIVE");
  } else {
    if((frame / 5) % 2 == 0) {
      u8g2.drawStr(35, 63, "WARNING");
    }
  }
}

// Targeting System
void drawTargetingSystem() {
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(30, 10, "TARGETING");
  
  // Crosshair
  int cx = 64;
  int cy = 35;
  
  u8g2.drawCircle(cx, cy, 12);
  u8g2.drawCircle(cx, cy, 16);
  
  u8g2.drawLine(cx - 20, cy, cx - 13, cy);
  u8g2.drawLine(cx + 20, cy, cx + 13, cy);
  u8g2.drawLine(cx, cy - 20, cx, cy - 13);
  u8g2.drawLine(cx, cy + 20, cx, cy + 13);
  
  // Rotating scanner
  float angle = frame * 0.15;
  int x1 = cx + cos(angle) * 10;
  int y1 = cy + sin(angle) * 10;
  int x2 = cx + cos(angle) * 16;
  int y2 = cy + sin(angle) * 16;
  u8g2.drawLine(x1, y1, x2, y2);
  
  // Target info
  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.drawStr(5, 56, "TGT:ACQ");
  u8g2.drawStr(50, 56, "RNG:25m");
  
  if((frame / 8) % 2 == 0) {
    u8g2.drawStr(95, 56, "LOCK");
  }
}

// Power Status and Diagnostics
void drawPowerStatus() {
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(15, 10, "POWER SYSTEMS");
  
  // Charging animation
  if(chargingUp) {
    chargeLevel += 2;
    if(chargeLevel >= 100) chargingUp = false;
  } else {
    chargeLevel -= 2;
    if(chargeLevel <= 0) chargingUp = true;
  }
  
  // Power cells
  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.drawStr(5, 22, "MAIN:");
  u8g2.drawFrame(35, 15, 88, 8);
  u8g2.drawBox(36, 16, (chargeLevel * 86) / 100, 6);
  
  u8g2.drawStr(5, 32, "BACKUP:");
  u8g2.drawFrame(35, 25, 88, 8);
  u8g2.drawBox(36, 26, 78, 6);
  
  // System status
  u8g2.drawStr(5, 45, "REPULSOR: OK");
  u8g2.drawStr(5, 53, "COMLINK: OK");
  u8g2.drawStr(5, 61, "SERVOS: OK");
  
  // Charge percentage
  char pct[10];
  sprintf(pct, "%d%%", chargeLevel);
  u8g2.setFont(u8g2_font_7x13_tr);
  u8g2.drawStr(95, 22, pct);
}

// Mandalorian Text Display 1 - Scrolling characters
void drawMandalorianText1() {
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(20, 10, "TRANSLATOR");
  
  // Mandalorian-style angular characters (custom glyphs)
  int offset = (frame / 2) % 128;
  
  // Draw stylized alien characters moving across screen
  for(int i = 0; i < 6; i++) {
    int x = (offset + i * 25) % 140 - 10;
    int y = 30;
    
    // Various angular character shapes
    switch(i % 5) {
      case 0: // Diamond shape
        u8g2.drawLine(x, y - 6, x + 6, y);
        u8g2.drawLine(x + 6, y, x, y + 6);
        u8g2.drawLine(x, y + 6, x - 6, y);
        u8g2.drawLine(x - 6, y, x, y - 6);
        break;
      case 1: // Arrow with cross
        u8g2.drawLine(x, y - 8, x, y + 8);
        u8g2.drawLine(x - 5, y, x + 5, y);
        u8g2.drawLine(x, y - 8, x - 4, y - 4);
        u8g2.drawLine(x, y - 8, x + 4, y - 4);
        break;
      case 2: // Triple line
        u8g2.drawLine(x - 3, y - 6, x - 3, y + 6);
        u8g2.drawLine(x, y - 6, x, y + 6);
        u8g2.drawLine(x + 3, y - 6, x + 3, y + 6);
        break;
      case 3: // Hexagon
        u8g2.drawLine(x - 4, y - 2, x - 4, y + 2);
        u8g2.drawLine(x - 4, y - 2, x - 2, y - 4);
        u8g2.drawLine(x - 2, y - 4, x + 2, y - 4);
        u8g2.drawLine(x + 2, y - 4, x + 4, y - 2);
        u8g2.drawLine(x + 4, y - 2, x + 4, y + 2);
        u8g2.drawLine(x + 4, y + 2, x + 2, y + 4);
        u8g2.drawLine(x + 2, y + 4, x - 2, y + 4);
        u8g2.drawLine(x - 2, y + 4, x - 4, y + 2);
        break;
      case 4: // Angular X
        u8g2.drawLine(x - 5, y - 6, x + 5, y + 6);
        u8g2.drawLine(x + 5, y - 6, x - 5, y + 6);
        u8g2.drawLine(x - 2, y - 8, x - 2, y + 8);
        break;
    }
  }
  
  // Static line of characters below
  int y2 = 48;
  for(int i = 0; i < 8; i++) {
    int x = 10 + i * 15;
    int charType = (i + frame / 20) % 5;
    
    switch(charType) {
      case 0:
        u8g2.drawLine(x, y2 - 4, x + 4, y2);
        u8g2.drawLine(x + 4, y2, x, y2 + 4);
        break;
      case 1:
        u8g2.drawCircle(x, y2, 3);
        u8g2.drawLine(x, y2 - 3, x, y2 + 3);
        break;
      case 2:
        u8g2.drawTriangle(x, y2 - 4, x - 3, y2 + 2, x + 3, y2 + 2);
        break;
      case 3:
        u8g2.drawLine(x - 3, y2 - 3, x + 3, y2 + 3);
        u8g2.drawCircle(x, y2, 2);
        break;
      case 4:
        u8g2.drawBox(x - 2, y2 - 3, 4, 6);
        u8g2.drawLine(x, y2 - 3, x - 3, y2 - 6);
        break;
    }
  }
  
  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.drawStr(25, 63, "DECODING...");
}

// Mandalorian Text Display 2 - Matrix style
void drawMandalorianText2() {
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(35, 10, "DATA LINK");
  
  // Vertical streams of characters
  for(int col = 0; col < 10; col++) {
    int x = 5 + col * 13;
    int streamOffset = (frame + col * 10) % 80;
    
    for(int row = 0; row < 6; row++) {
      int y = 15 + row * 10 - streamOffset;
      
      if(y > 10 && y < 60) {
        // Fade effect - bottom characters brighter
        if(row < 2) {
          int charStyle = (col + row + frame / 10) % 6;
          
          switch(charStyle) {
            case 0:
              u8g2.drawLine(x, y, x + 4, y);
              u8g2.drawLine(x + 2, y - 2, x + 2, y + 2);
              break;
            case 1:
              u8g2.drawCircle(x + 2, y, 2);
              break;
            case 2:
              u8g2.drawLine(x, y - 2, x + 4, y + 2);
              break;
            case 3:
              u8g2.drawBox(x, y - 2, 4, 4);
              break;
            case 4:
              u8g2.drawTriangle(x, y + 2, x + 2, y - 2, x + 4, y + 2);
              break;
            case 5:
              u8g2.drawLine(x, y - 2, x + 2, y);
              u8g2.drawLine(x + 2, y, x + 4, y - 2);
              break;
          }
        }
      }
    }
  }
  
  u8g2.setFont(u8g2_font_5x7_tr);
  u8g2.drawStr(15, 63, "RECEIVING DATA");
}
