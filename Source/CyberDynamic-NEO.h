/*

CyberDynamic-NEO - Library for Arduino NEO

*/


#ifndef CyberDynamic_NEO_h
#define CyberDynamic_NEO_h

#include "Arduino.h"
#include <FastLED.h>

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

FASTLED_USING_NAMESPACE


// Tested using these FastLED settings

#define LED_DRIVER  WS2811	// LED Driver Type
#define COLOR_ORDER GRB		// LED Colour Order

#define FADEBY_MS		20		// Defult Fadeby timing
#define NEOPROBABLILITY	40		// Probability settings for Random Number Selection

#define MAX_BRIGHTNESS     100	// Set maximum brightness
#define FRAMES_PER_SECOND  120	// Set number of frames per second


// FX List
#define FX_Count					27

#define FX_Off 						0

#define FX_On	 					1
#define FX_Stars 					2
#define FX_Wind 					3
#define FX_Whirl					4
#define FX_Follow					5
#define FX_FadeIn					6
#define FX_FadeOut					7
#define FX_Rainbow 					8
#define FX_RainbowStars				9
#define FX_Strobe					10
#define FX_CylonBounce				11
#define FX_NewKITT					12
#define FX_CenterToOutside			13
#define FX_OutsideToCentre			14
#define FX_LeftToRight				15
#define FX_RightToLeft				16
#define FX_Twinkle					17
#define FX_TwinkleRandow			18
#define FX_Sparkle					19
#define FX_SnowSparkle				20
#define FX_RunningLights			21
#define FX_ColourWipe				22
#define FX_Wheel					23
#define FX_TheatreChase				24
#define FX_Fire						25
#define FX_BouncingColouredBalls	26
#define FX_MeteroRain				27

#define FX_Hazard					28
#define FX_Police					29
#define FX_Vortex					99

#define COL_BLACK					CRGB::Black
#define COL_WHITE					CRGB::White
#define COL_GOLD					CRGB::Gold
#define COL_GOLDENROD				CRGB::Goldenrod
#define COL_DARKGOLDENROD			CRGB::DarkGoldenrod
#define COL_MISTYROSE				CRGB::MistyRose
#define COL_MOCCASIN				CRGB::Moccasin
#define COL_NAVAJOWHITE				CRGB::NavajoWhite
#define COL_THISTLE					CRGB::Thistle
#define COL_YELLOW					CRGB::Yellow

#define COL_RED						CRGB::Red
#define COL_TOMATO					CRGB::Tomato
#define COL_FIREBRICK				CRGB::FireBrick
#define COL_DARKRED					CRGB::DarkRed
#define COL_CRIMSON					CRGB::Crimson
#define COL_DARKORANGE				CRGB::DarkOrange
#define COL_CHOCOLATE				CRGB::Chocolate
#define COL_CORAL					CRGB::Coral
#define COL_SALMON					CRGB::Salmon
#define COL_LIGHTCORAL				CRGB::LightCoral
#define COL_LIGHTCYAN				CRGB::LightCyan
#define COL_LIGHTPINK				CRGB::LightPink
#define COL_PINK					CRGB::Pink
#define COL_ROSYBROWN				CRGB::RosyBrown
#define COL_PLUM					CRGB::Plum
#define COL_PALEVIOLETRED			CRGB::PaleVioletRed
#define COL_FUCHSIA					CRGB::Fuchsia
#define COL_HOTPINK					CRGB::HotPink
#define COL_ORCHID					CRGB::Orchid
#define COL_INDIANRED				CRGB::IndianRed
#define COL_MAROON					CRGB::Maroon
#define COL_LIGHTSALMON				CRGB::LightSalmon
#define COL_MAGENTA					CRGB::Magenta
#define COL_MEDIUMVIOLETRED			CRGB::MediumVioletRed
#define COL_ORANGE					CRGB::Orange
#define COL_ORANGERED				CRGB::OrangeRed
#define COL_PERU					CRGB::Peru
#define COL_PLAID					CRGB::Plaid
#define COL_SANDYBROWN				CRGB::SandyBrown
#define COL_SIENNA					CRGB::Sienna
#define COL_VIOLET					CRGB::Violet

#define COL_GREEN					CRGB::Green
#define COL_FORESTGREEN				CRGB::ForestGreen
#define COL_DARKGREEN				CRGB::DarkGreen
#define COL_DARKOLIVEGREEN			CRGB::DarkOliveGreen
#define COL_CHARTREUSE				CRGB::Chartreuse
#define COL_DARKSEAGREEN			CRGB::DarkSeaGreen
#define COL_DAKCYAN					CRGB::DarkCyan
#define COL_CYAN					CRGB::Cyan
#define COL_DARKGREEN				CRGB::DarkGreen
#define COL_GREENYELLOW				CRGB::GreenYellow
#define COL_LAWNGREEN				CRGB::LawnGreen
#define COL_LIGHTGREEN				CRGB::LightGreen
#define COL_PALEGREEN				CRGB::PaleGreen
#define COL_LIME					CRGB::Lime
#define COL_OLIVE					CRGB::Olive
#define COL_OLIVEDRAB				CRGB::OliveDrab
#define COL_LIMEGREEN				CRGB::LimeGreen
#define COL_MEDIUMSEAGREEN			CRGB::MediumSeaGreen
#define COL_MEDIUMSPRINGGREEN		CRGB::MediumSpringGreen
#define COL_MEDIUMTURQUOISE			CRGB::MediumTurquoise
#define COL_SEAGREEN				CRGB::SeaGreen
#define COL_SPRINGGREEN				CRGB::SpringGreen
#define COL_YELLOWGREEN				CRGB::YellowGreen

#define COL_BLUE					CRGB::Blue
#define COL_MEDIUMBLUE				CRGB::MediumBlue
#define COL_INDIGO					CRGB::Indigo
#define COL_INDIGO					CRGB::Indigo
#define COL_PURPLE					CRGB::Purple
#define COL_DARKSLATEBLUE			CRGB::DarkSlateBlue
#define COL_NAVY					CRGB::Navy
#define COL_BLUEVIOLET				CRGB::BlueViolet
#define COL_DARKMAGENTA				CRGB::DarkMagenta
#define COL_DARKORCHID				CRGB::DarkOrchid
#define COL_AMETHYST				CRGB::Amethyst
#define COL_DODGERBLUE				CRGB::DodgerBlue
#define COL_AQUA					CRGB::Aqua
#define COL_CADETBLUE				CRGB::CadetBlue
#define COL_CORNFLOWERBLUE			CRGB::CornflowerBlue
#define COL_POWDERBLUE				CRGB::PowderBlue
#define COL_LIGHTBLUE				CRGB::LightBlue
#define COL_LIGHTSEAGREEN			CRGB::LightSeaGreen
#define COL_LIGHTSKYBLUE			CRGB::LightSkyBlue
#define COL_PALETURQUOISE			CRGB::PaleTurquoise
#define COL_LIGHTSTEELBLUE			CRGB::LightSteelBlue
#define COL_MEDIUMAQAUMARINE		CRGB::MediumAquamarine
#define COL_MEDIUMPURPLE			CRGB::MediumPurple
#define COL_MEDIUMSLATEBLUE			CRGB::MediumSlateBlue
#define COL_ROYALBLUE				CRGB::RoyalBlue
#define COL_SKYBLUE					CRGB::SkyBlue
#define COL_SLATEBLUE				CRGB::SlateBlue
#define COL_STEELBLUE				CRGB::SteelBlue
#define COL_TEAL					CRGB::Teal
#define COL_TURQUOISE				CRGB::Turquoise




class CyberDynamic_NEO
{
  public:
	CyberDynamic_NEO(bool isDebug, int thisLEDCount);
  	CyberDynamic_NEO(void);
	
	void Init(void);
	void Loop(void);
	
	void SelectFX(byte thisFX);
	int CurrentFX(void);
	void SetColour(CRGB thisColour);
	void SetHue(uint8_t thisHue);
	void SetRainbow(bool isRainbow);
	CRGB SelectColour(CRGB thisCurrentColour);

	// FX
    void Stars(void);
    void Wind(void);
    void Whirl(void);
    void Follow(void);
    void FadeOut(void);
    void FadeIn(void);
    void Rainbow(void);
    void RainbowStars(void);
	void FadeInOut(void);
	void Strobe(void); 
	void CylonBounce(void);
	void NewKITT(void);
	void Twinkle(void);
	void TwinkleRandom(void);
	void Sparkle(void);
	void SnowSparkle(void);
	void RunningLights(void);
	void colorWipe(void);
	void theatherChase(void);
	void Fire(void);
	void BouncingBalls(void);
	void BouncingColoredBalls(void);
	void meteorRain(void);
	
    void Hazard(void);
    void Police(void);
	
	// FX Functions

    void FXF_Stars(int thisProbability);
    void FXF_FadeInOut(byte red, byte green, byte blue);
	void FXF_Strobe(byte red, byte green, byte blue, int StrobeCount, int FlashDelay, int EndPause);
	void FXF_CylonBounce(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay);
	void FXF_NewKITT(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay);
	void FXF_CenterToOutside(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay);
	void FXF_OutsideToCenter(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay);
	void FXF_LeftToRight(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay);
	void FXF_RightToLeft(byte red, byte green, byte blue, int EyeSize, int SpeedDelay, int ReturnDelay);
	void FXF_Twinkle(byte red, byte green, byte blue, int Count, int SpeedDelay, boolean OnlyOne);
	void FXF_TwinkleRandom(int Count, int SpeedDelay, boolean OnlyOne);
	void FXF_Sparkle(byte red, byte green, byte blue, int SpeedDelay);
	void FXF_SnowSparkle(byte red, byte green, byte blue, int SparkleDelay, int SpeedDelay);
	void FXF_RunningLights(byte red, byte green, byte blue, int WaveDelay);
	void FXF_colorWipe(byte red, byte green, byte blue, int SpeedDelay);
	byte * FXF_Wheel(byte WheelPos);
	void FXF_theaterChase(byte red, byte green, byte blue, int SpeedDelay);
	void FXF_Fire(int Cooling, int Sparking, int SpeedDelay);
	void FXF_setPixelHeatColor (int Pixel, byte temperature);
	void FXF_BouncingColoredBalls(int BallCount, byte colors[][3], boolean continuous);
	void FXF_meteorRain(byte red, byte green, byte blue, byte meteorSize, byte meteorTrailDecay, boolean meteorRandomDecay, int SpeedDelay);
	void FXF_UpdateRainbow(int thisAmount);

	
	

	// Randomize FX
	
    void Vortex(void);
    void NextFX(void);
    void PreviousFX(void);
	
	// FX Support Methods
	
	void UpdateColourCycle(void);
	void setAll(byte red, byte green, byte blue);
	void setPixel(int Pixel, byte red, byte green, byte blue);
	void fadeToBlack(int ledNo, byte fadeValue);
	
  private:
	bool IsRainbow = false; 						// Set Rainbow State
	CRGB CurrentColour = CRGB::White; 				// Rotating "base color" used by MOST of the patterns
	uint8_t CurrentHue = 0;							// Global Hue State
  
    bool isDebug = false;	
	byte LEDCount = 0;
	const byte DataPin = 0;
	
	uint8_t CurrentFX = 0; 							// Current FX

	CRGB *NEOLEDS;
	
	byte HazardColour = 1;							// Set Hazard and Police FX Default State
	bool ColourWipeFull = false;
	
};

#endif