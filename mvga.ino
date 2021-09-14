// 1pxの色を2bitで表現している つまり一回の通信で4px分のデータを送信することができる。
// 1pxの色を3bitで表現するようにすればいいってことだよなぁ！？これ、1.5倍メモリを消費するってことか
// 白111　赤100 緑 010 青 001
// 前か後の2bitは捨てるしかないかな？ 2pxしか送れない 00100111 このデータを送ったとして赤白って2pxのデータが渡せる。
#define HSYNCPIN 3
#define VSYNCPIN 9
#define COLORRED 6
#define COLORGREEN 7
#define COLORBLUE 5
#define VGAX_HEIGHT 65
#define VGAX_BWIDTH 30
#define VGAX_WIDTH (VGAX_BWIDTH*4)
#define VGAX_BSIZE (VGAX_BWIDTH*VGAX_HEIGHT)

#define IMG_MARIOMASK_WIDTH 16
#define IMG_MARIOMASK_BWIDTH 4
#define IMG_MARIOMASK_HEIGHT 16
#define IMG_MARIOMASK_SPRITES_CNT 8

#define SKIPLINES 40

//data size=512 bytes
// 255が1byteの最大
const unsigned char img_mariomask_data[IMG_MARIOMASK_SPRITES_CNT][IMG_MARIOMASK_HEIGHT][IMG_MARIOMASK_BWIDTH] PROGMEM={
{ { 255, 255, 255, 255, }, { 255, 192,   3, 255, }, { 255,   0,   0,  63, }, { 252,   0,   0,  15, }, { 252,   0,   0,  63, }, { 240,   0,   0,  15, }, { 240,   0,   0,  15, }, { 252,   0,   0,  63, }, { 255,   0,   0, 255, }, { 252,   0,   3, 255, }, { 240,   0,   0, 255, }, { 240,   0,   0, 255, }, { 252,   0,   0, 255, }, { 252,   0,   3, 255, }, { 255,   0,   3, 255, }, { 255,   0,   3, 255, }, },
{ { 255, 255, 255, 255, }, { 255, 192,   3, 255, }, { 255,   0,   0,  63, }, { 252,   0,   0,  15, }, { 252,   0,   0,  63, }, { 240,   0,   0,  15, }, { 240,   0,   0,  15, }, { 252,   0,   0,  63, }, { 255,   0,   0, 255, }, { 252,   0,   0,  63, }, { 252,   0,   0,  15, }, { 240,   0,   0,  15, }, { 240,   0,   0,  63, }, { 252,   0,   0,  63, }, { 252,   0,   0,  63, }, { 255,   3, 192, 255, }, },
{ { 255, 192,  15, 255, }, { 255,   0,   0,  63, }, { 252,   0,   0,  15, }, { 252,   0,   0,  63, }, { 240,   0,   0,  15, }, { 240,   0,   0,  15, }, { 252,   0,   0,  63, }, { 252,   0,   0, 255, }, { 192,   0,   0,  63, }, {   0,   0,   0,  15, }, {   0,   0,   0,   3, }, { 192,   0,   0,   3, }, { 240,   0,   0,  15, }, { 192,   0,   0,  15, }, { 192,   3,   0,  63, }, { 240,   3, 192, 255, }, },
{ { 255, 192,  15,   3, }, { 255,   0,   0,   0, }, { 252,   0,   0,   0, }, { 252,   0,   0,   3, }, { 240,   0,   0,   3, }, { 240,   0,   0,   3, }, { 252,   0,   0,  15, }, { 252,   0,   0,  15, }, { 240,   0,   0,  63, }, { 192,   0,   0,   3, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, { 192,   0,   0,   3, }, {   0,   0,   0,   3, }, {   0,   0,  63,  15, }, { 195,   3, 255, 255, }, },
{ { 255, 192,   3, 255, }, { 252,   0,   0,  63, }, { 240,   0,   0,  15, }, { 192,   0,   0,   3, }, { 192,   0,   0,   3, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, { 192,   0,   0,   3, }, { 240,   0,   0,  15, }, { 240,   0,   0,  15, }, { 252,   0,   0,  63, }, { 255,   0,   0, 255, }, },
{ { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 255, 240,  15, 255, }, { 252,   0,   0,  63, }, { 192,   0,   0,   3, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, { 240,   0,   0,  15, }, { 192,   0,   0,   3, }, },
{ { 255, 240,  15, 255, }, { 255, 192,   3, 255, }, { 255,   0,   0, 255, }, { 240,   0,   0,  15, }, { 192,   0,   0,   3, }, { 240,   0,   0,  15, }, { 192,   0,   0,   3, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, { 192,   0,   0,   3, }, { 255,   0,   0,  63, }, { 252,   0,   0,  15, }, { 240,   0,   0,   3, }, { 240,   0,   0,   3, }, { 252,  15, 192,  15, }, },
{ { 255, 240,  15, 255, }, { 255, 192,   3, 255, }, { 255,   0,   0, 255, }, { 240,   0,   0,  15, }, { 192,   0,   0,   3, }, { 240,   0,   0,  15, }, { 192,   0,   0,   3, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, { 192,   0,   0,   3, }, { 252,   0,   0, 255, }, { 240,   0,   0,  63, }, { 192,   0,   0,  15, }, { 192,   0,   0,  15, }, { 240,   3, 240,  63, }, }
};
//image generated from 2BITIMAGE - by Sandro Maffiodo
#define IMG_MARIO_WIDTH 16
#define IMG_MARIO_BWIDTH 4
#define IMG_MARIO_HEIGHT 16
#define IMG_MARIO_SPRITES_CNT 22
//data size=1408 bytes
const unsigned char img_mario_data[IMG_MARIO_SPRITES_CNT][IMG_MARIO_HEIGHT][IMG_MARIO_BWIDTH] PROGMEM={
{ {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,  42, 168,   0, }, {   0, 170, 170, 128, }, {   0,  15,  48,   0, }, {   3, 195,  63, 192, }, {   3, 195, 207, 192, }, {   0,  63,   0,   0, }, {   0,  15, 252,   0, }, {   0, 162, 160,   0, }, {   2, 168, 168,   0, }, {   2, 168,  84,   0, }, {   0, 252,  20,   0, }, {   0, 250, 128,   0, }, {   0,  42, 160,   0, }, {   0,   0,   0,   0, }, },
{ {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,  42, 168,   0, }, {   0, 170, 170, 128, }, {   0,  15,  48,   0, }, {   3, 195,  63, 192, }, {   3, 195, 207, 192, }, {   0,  63,   0,   0, }, {   0,  15, 252,   0, }, {   0, 162, 162,   0, }, {   0, 168, 168, 128, }, {   3, 232,  20, 192, }, {   3, 192,  20,   0, }, {   0,   0,   2,   0, }, {   0, 168,  42,   0, }, {   0,   0,   0,   0, }, },
{ {   0,   0,   0,   0, }, {   0,  42, 160,   0, }, {   0, 170, 170, 128, }, {   0,  15,  48,   0, }, {   3, 195,  63, 192, }, {   3, 195, 207, 192, }, {   0,  63,   0,   0, }, {   0,  15, 252,   0, }, {   2, 162, 160,   0, }, {  62, 168, 168, 128, }, {  63, 161,  84, 176, }, {  15,   5,  84,  48, }, {   0,   1,  82, 128, }, {  10,   0,  10, 128, }, {  10, 160,  42,   0, }, {   0,   0,   0,   0, }, },
{ {   0,   0,   0,   0, }, {   0,  42, 160,   0, }, {   0, 170, 170,   0, }, {   0,  15,  48,  32, }, {   3, 195,  63, 224, }, {   3, 195, 207, 224, }, {   0,  63,   0,   0, }, {   0,  15, 255, 128, }, {   2, 162, 162,   0, }, {   0, 168, 168,   0, }, {  63,  40,  85,  40, }, {  63,  33,  84, 168, }, {   0,   4,   0, 160, }, {  42,  16,   0, 160, }, {  40,   0,   0,   0, }, {   0,   0,   0,   0, }, },
{ {   0,   0,   0,   0, }, {   0,  61, 124,   0, }, {   3, 245,  95, 192, }, {   5,  95, 245,  80, }, {   5, 127, 253,  80, }, {  53, 255, 255,  92, }, {  61, 255, 255, 124, }, {  61, 255, 255, 124, }, {  53, 127, 253,  92, }, {  21,  95, 245,  84, }, {  21,   0,   0,  84, }, {   0, 243, 207,   0, }, {   3, 243, 207, 192, }, {   3, 255, 255, 192, }, {   0, 255, 255,   0, }, {   0,   0,   0,   0, }, },
{ {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,   0,   0,   0, }, {   0,   5,  80,   0, }, {   3, 247, 223, 192, }, {  16,  61, 124,   4, }, {  20,   0,   0,  20, }, {   2,  63, 252, 128, }, {  10, 175, 250, 160, }, {  42, 160,  10, 168, }, },
{ {   0,   0,   0,   0, }, {   0,   5,  80,   0, }, {   0,  21,  84,   0, }, {   0,  31, 244,   0, }, {   0,   7, 208,   0, }, {   1, 192,   3,  64, }, {   5, 192,   3,  80, }, {  23, 205, 115, 212, }, {  23, 245,  95, 212, }, {   5,  80,   5,  80, }, {   0,  15, 240,   0, }, {   0,  63, 255,   0, }, {   2,  63, 254, 160, }, {  10, 143, 250, 168, }, {  10, 160,  42, 128, }, {   2, 160,  32,   0, }, },
{ {   0,   0,   0,   0, }, {   0,   5,  80,   0, }, {   0,  21,  84,   0, }, {   0,  31, 244,   0, }, {   0,   7, 208,   0, }, {   1, 192,   3,  64, }, {   5, 192,   3,  80, }, {  23, 205, 115, 212, }, {  23, 245,  95, 212, }, {   5,  80,   5,  80, }, {   0,  15, 240,   0, }, {   0, 255, 252,   0, }, {  10, 191, 252, 128, }, {  42, 175, 242, 160, }, {   0, 168,  10, 160, }, {   0,   8,  10, 128, }, },
{ {  63, 255,  63, 255, }, {  58, 170,  58, 170, }, {  58, 170,  58, 170, }, {   0,   0,   0,   0, }, { 255,  63, 255,  63, }, { 170,  58, 170,  58, }, { 170,  58, 170,  58, }, {   0,   0,   0,   0, }, {  63, 255,  63, 255, }, {  58, 170,  58, 170, }, {  58, 170,  58, 170, }, {   0,   0,   0,   0, }, { 255,  63, 255,  63, }, { 170,  58, 170,  58, }, { 170,  58, 170,  58, }, {   0,   0,   0,   0, }, },
{ { 192,   0,   0,   3, }, {  15, 255, 255, 240, }, {  62, 170, 170, 168, }, {  58, 175, 250, 160, }, {  58, 176,  12, 168, }, {  58, 178, 172, 160, }, {  58, 178, 188, 168, }, {  58, 130, 194, 160, }, {  58, 170, 202, 168, }, {  58, 170,  10, 160, }, {  58, 170, 170, 168, }, {  58, 170, 202, 160, }, {  58, 170,  10, 168, }, {  10, 170, 170, 160, }, {   8, 136, 136, 128, }, { 192,   0,   0,   3, }, },
{ { 192,   0,   0,   3, }, {  15, 255, 255, 240, }, {  62, 170, 170, 168, }, {  58, 170, 170, 160, }, {  58, 170, 170, 168, }, {  58, 170, 170, 160, }, {  58, 170, 170, 168, }, {  58, 170, 170, 160, }, {  58, 170, 170, 168, }, {  58, 170, 170, 160, }, {  58, 170, 170, 168, }, {  58, 170, 170, 160, }, {  58, 170, 170, 168, }, {  10, 170, 170, 160, }, {   8, 136, 136, 128, }, { 192,   0,   0,   3, }, },
{ { 240,   0,   0,   0, }, { 197,  85,  85,  85, }, {  21,  85,  85,  85, }, {  21,  85,  85,  85, }, {  21,  85,  69,  85, }, {   5,  69,  69,  69, }, { 196,  68,  68,  68, }, { 196,  68,  68,  68, }, { 192,  68,   4,   4, }, { 202,   4, 160, 160, }, { 202, 132, 170, 168, }, { 207, 226, 186, 251, }, { 207, 250, 255, 255, }, { 207, 250, 255, 255, }, { 207, 255, 255, 255, }, { 207, 255, 175, 255, }, },
{ {   0,   0,   0,   0, }, {  85,  85,  85,  85, }, {  85,  85,  85,  85, }, {  85,  85,  85,  85, }, {  85,  85,  69,  85, }, {  69,  69,  69,  69, }, {  68,  68,  68,  68, }, {  68,  68,  68,  68, }, {  64,  68,   4,   4, }, {  74,   4, 160, 160, }, {  42, 132, 170, 168, }, { 175, 226, 186, 251, }, { 255, 250, 255, 255, }, { 255, 250, 255, 255, }, { 255, 255, 255, 255, }, { 255, 255, 175, 255, }, },
{ {   0,   0,   0,  15, }, {  85,  85,  85,  83, }, {  85,  85,  85,  84, }, {  85,  85,  85,  84, }, {  85,  85,  69,  84, }, {  69,  69,  69,  68, }, {  68,  68,  68,  68, }, {  68,  68,  68,  68, }, {  64,  68,   4,   4, }, {  74,   4, 160, 160, }, {  42, 132, 170, 160, }, { 175, 226, 186, 163, }, { 255, 250, 254, 163, }, { 255, 250, 254, 163, }, { 255, 255, 254, 163, }, { 255, 255, 174, 163, }, },
{ { 240,   0,   0,  15, }, { 197,  85,  85,  83, }, {  21,  85,  85,  84, }, {  21,  85,  85,  84, }, {  21,  85,  69,  84, }, {   5,  69,  69,  68, }, { 196,  68,  68,  68, }, { 196,  68,  68,  68, }, { 192,  68,   4,   4, }, { 202,   4, 160, 160, }, { 202, 132, 170, 160, }, { 207, 226, 186, 163, }, { 207, 250, 254, 163, }, { 207, 250, 254, 163, }, { 207, 255, 254, 163, }, { 207, 255, 174, 163, }, },
{ {   0,   0,   0,   0, }, {  23, 255, 255, 255, }, {  21,  95, 213,  85, }, {  21,  95, 245,  85, }, {  21,  95, 245,  85, }, {  21,  95, 245,  85, }, {  21,  95, 245,  85, }, {  21,  95, 245,  85, }, {  21,  95, 245,  85, }, {  21,  95, 245,  85, }, {  21,  95, 245,  85, }, {  21,  95, 245,  85, }, {  21,  95, 245,  85, }, {  21,  95, 245,  85, }, {   0,   0,   0,   0, }, { 240,   0,   0,   0, }, },
{ {   0,   0,   0,   0, }, { 255, 255, 213,  84, }, {  85,  85,  85,  80, }, {  85,  85,  85,  80, }, {  85,  85,  85,  80, }, {  85,  85,  85,  80, }, {  85,  85,  85,  80, }, {  85,  85,  85,  80, }, {  85,  85,  85,  80, }, {  85,  85,  85,  80, }, {  85,  85,  85,  80, }, {  85,  85,  85,  80, }, {  85,  85,  85,  80, }, {  85,  85,  85,  80, }, {   0,   0,   0,   0, }, {   0,   0,   0,  15, }, },
{ {  85,  85,  85,  15, }, {  85,  85,  85,  15, }, {  85,  85,  85,  15, }, {  85,  85,  85,  15, }, {  85,  85,  85,  15, }, {  85,  85,  85,  15, }, {  85,  85,  85,  15, }, {  85,  85,  85,  15, }, {  85,  85,  85,  15, }, {  85,  85,  85,  15, }, {  85,  85,  85,  15, }, {  85,  85,  85,  15, }, {  85,  85,  85,  15, }, {  85,  85,  85,  15, }, {  85,  85,  85,  15, }, {  85,  85,  85,  15, }, },
{ { 241,  85, 253,  85, }, { 241,  85, 253,  85, }, { 241,  85, 253,  85, }, { 241,  85, 253,  85, }, { 241,  85, 253,  85, }, { 241,  85, 253,  85, }, { 241,  85, 253,  85, }, { 241,  85, 253,  85, }, { 241,  85, 253,  85, }, { 241,  85, 253,  85, }, { 241,  85, 253,  85, }, { 241,  85, 253,  85, }, { 241,  85, 253,  85, }, { 241,  85, 253,  85, }, { 241,  85, 253,  85, }, { 241,  85, 253,  85, }, },
{ { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 255, 255, 255, 192, }, { 255, 255, 240,  21, }, { 255, 255, 197,  85, }, { 255, 255,  21,  85, }, { 255, 255,  21,  21, }, { 255,   0,  85,  85, }, { 252,  85,  69,  85, }, { 252,  85,  85,  85, }, { 241,  85,  21,  85, }, { 241,  85,  85,  85, }, { 241,  85,  85,  85, }, },
{ { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 240,  15, 192,  63, }, { 197,  83,  21,  79, }, {  21,  84,  85,  80, }, {  84,  85,  84,  85, }, {  85,  85,  85,  85, }, {  85,  85,  85,  85, }, {  85,  85,  85,  85, }, {  85,  85,  81,  85, }, {  85,  85,  85,  85, }, {  85,  85,  85,  85, }, {  85,  85,  85,  85, }, {  85,  85,  85,  85, }, {  85,  85,  85,  85, }, },
{ { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 255, 255, 255, 255, }, { 192,  15, 255, 255, }, {  21,  83, 255, 255, }, {  85,  84, 255, 255, }, {  85,  84, 255, 255, }, {  84,  85,   0, 255, }, {  85,  81,  85,  63, }, {  85,  85,  85,  79, }, {  85,  85,  81,  79, }, {  85,  85,  85,  79, }, {  85,  85,  85,  83, }, {  85,  85,  84,  84, }, {  85,  85,  85,  84, }, }
};

void setup() {
  begin();
  clear(11);
}
static byte afreq, afreq0;
unsigned vtimer;
static byte aline, rlinecnt;
static byte vskip;
byte vgaxfb[VGAX_HEIGHT*VGAX_BWIDTH];

//VSYNC interrupt
ISR(TIMER1_OVF_vect) {
  aline=-1;
  vskip=SKIPLINES;
  vtimer++;
  rlinecnt=0;
}
//HSYNC interrupt
ISR(TIMER2_OVF_vect) {
  /*
  NOTE: I prefer to generate the line here, inside the interrupt.
  Gammon's code generate the line pixels inside main().
  My versin generate the signal using only interrupts, so inside main() function
  you can do anything you want. Your code will be interrupted when VGA signal
  needs to be generated
  */
  //generate audio modulation. around 15 clocks
  asm volatile(                                   //4c to load Z and Y
    "      ld r16, z                        \n\t" //c1 r16=afreq
    "      cpi %[freq0], 0                  \n\t" //c1 afreq0==0 ?
    "play_audio:                            \n\t" 
    "      cpi r16, 0                       \n\t" //c1 afreq==0 ?
    "      brne dont_flip_audio_pin         \n\t" //c1/2 *1
    "flip_audio_pin:                        \n\t" 
    "      ldi r18, 1                       \n\t" //c1
    "      out %[audiopin], r18             \n\t" //c1
    "      st Z, %[freq0]                   \n\t" //c1 afreq=afreq0
    "      rjmp end                         \n\t" //c2
    "dont_flip_audio_pin:                   \n\t" 
    "      dec r16                          \n\t" //c1
    "      st z, r16                        \n\t" //c1
    "end:                                   \n\t"
  :
  : "z" (&afreq),
    [freq0] "r" (afreq0),
    [audiopin] "i" _SFR_IO_ADDR(PINC)
  : "r16", "r18");

  //check vertical porch
  if (vskip) {
      vskip--;
      return;
  }
  if (rlinecnt<VGAX_HEIGHT) {   
    //interrupt jitter fix (needed to keep signal stable)
    //code from https://github.com/cnlohr/avrcraft/tree/master/terminal
    //modified from 4 nop align to 8 nop align
    #define DEJITTER_OFFSET 1
    #define DEJITTER_SYNC -2
    asm volatile(
      "     st Z, r16             \n\t" //
      "     lds r16, %[timer0]    \n\t" //
      "     subi r16, %[tsync]    \n\t" //
      "     andi r16, 7           \n\t" //
      "     call TL               \n\t" //絶対アドレス TLを指定
      "TL:                        \n\t" //
      "     pop r31               \n\t" //1バイトの標準I/Oレジスタの内容を汎用レジスタに転送する。
      "     pop r30               \n\t" //
      "     adiw r30, (LW-TL-5)   \n\t" //
      "     add r30, r16          \n\t" //
      "   adc r31, __zero_reg__ \n\t" //
      "     ijmp                  \n\t" //
      "LW:                        \n\t" //
      "     nop                   \n\t" //
      "     nop                   \n\t" //
      "     nop                   \n\t" //
      "     nop                   \n\t" //
      "     nop                   \n\t" //
      "     nop                   \n\t" //
      "     nop                   \n\t" //
      //"   nop                   \n\t" //
      "LBEND:                     \n\t" //
    :
    : [timer0] "i" (&TCNT0),
      [toffset] "i" ((uint8_t)DEJITTER_OFFSET),
      [tsync] "i" ((uint8_t)DEJITTER_SYNC)
    : "r30", "r31", "r16", "r17");
    /*
    Output all pixels.

    NOTE: My trick here is to unpack 4 pixels and shift them before writing to
    PORTD.

    Pixels are packed as 0b11223344 because the first pixel write have no time
    to perform a shift (ld, out) and must be prealigned to the two upper bits 
    of PORTD, where the two wires of the VGA DSUB are connected. The second, 
    the third and the forth pixels are shifted left using mul opcode instead 
    of a left shift opcode. Shift opcodes are slow and can shift only 1 bit at
    a time, using 1 clock cycle. mul is faster.

    Instead of using a loop i use the .rept assembler directive to generate an 
    unrolled loop of 30 iterations.
    */
    Serial.println("--------------");
    Serial.println((byte*)vgaxfb);
    Serial.println(rlinecnt);
    asm volatile (
      "    ldi r20, 4       \n\t" //const for <<2bit r20に定数4を転送
      ".rept 30             \n\t" //output 4 pixels for each iteration
      "    ld r16, Z+       \n\t" // １バイトのデータメモリを汎用レジスタに転送。 事後増加付きZﾚｼﾞｽﾀ間接での取得 	Rd ← (Z), Z ← Z + 1
      "    out %[port], r16 \n\t" //write pixel 1 out I,r 1バイトの汎用レジスタの内容を標準I/Oレジスタに転送する。
      "    mul r16, r20     \n\t" //<<2 汎用レジスタ間でに乗算させる。r16*r20ってこと？　r16*4
      "    out %[port], r0  \n\t" //write pixel 2
      "    mul r0, r20      \n\t" //<<4 r0*4
      "    out %[port], r0  \n\t" //write pixel 3
      "    mul r0, r20      \n\t" //<<6
      "    out %[port], r0  \n\t" //write pixel 4
      ".endr                \n\t" //
      "    nop              \n\t" //expand last pixel
      "    ldi r16, 0       \n\t" //
      "    out %[port], r16 \n\t" //write black for next pixels
    :
    : [port] "I" (_SFR_IO_ADDR(PORTD)), // ポートD (デジタルピン0から7) // 入力オペランド　[マクロ名2] "制約" (変数名2)
      "z" "I" (/*rline*/(byte*)vgaxfb + rlinecnt*VGAX_BWIDTH) // vgaxfb[VGAX_HEIGHT(60)*VGAX_BWIDTH(30)], rlinecnt*VGAX_BWIDTH 
    : "r16", "r17", "r20", "r21", "memory");
    // VGAX_BWIDTH=30
    // rlinecntは0から増えていく？

    //increment framebuffer line counter after 6 VGA lines
    #if defined(__AVR_ATmega2560__) && defined(ATMEGA2560_MAXRES)
      #define CLONED_LINES (2-1)
    #else
      #define CLONED_LINES (6-1)
    #endif
    if (++aline==CLONED_LINES) { 
      aline=-1;
      rlinecnt++;
    } else {
    }
  } 
}

void loop() {
  static byte sidx=1;
  blitwmask((byte*)(img_mario_data[sidx]), (byte*)(img_mariomask_data[sidx]), IMG_MARIO_WIDTH, IMG_MARIO_HEIGHT, rand()%VGAX_WIDTH-IMG_MARIO_WIDTH/2, rand()%VGAX_HEIGHT-IMG_MARIO_HEIGHT/2);
  sidx=sidx==1 ? 2 : 1;
  static unsigned cnt;
  /*if (cnt>=180) {
    cnt=0;
    clear(3);
  }*/
}


void begin() {
  cli();
    //disable TIMER0 interrupt
  TIMSK0=0;
  TCCR0A=0;
  TCCR0B=(1 << CS00); //enable 16MHz counter (used to fix the HSYNC interrupt jitter)
  OCR0A=0;
  OCR0B=0;
  TCNT0=0;
  //TIMER1 - vertical sync pulses
  pinMode(VSYNCPIN, OUTPUT);
  TCCR1A=bit(WGM11) | bit(COM1A1);
  TCCR1B=bit(WGM12) | bit(WGM13) | bit(CS12) | bit(CS10); //1024 prescaler
  ICR1=259; //16666 / 64 uS=260 (less one)
  OCR1A=0; //64 / 64 uS=1 (less one)
  TIFR1=bit(TOV1); //clear overflow flag
  TIMSK1=bit(TOIE1); //interrupt on overflow on TIMER1
  //TIMER2 - horizontal sync pulses
  pinMode(HSYNCPIN, OUTPUT);
  TCCR2A=bit(WGM20) | bit(WGM21) | bit(COM2B1); //pin3=COM2B1
  TCCR2B=bit(WGM22) | bit(CS21); //8 prescaler
  OCR2A=63; //32 / 0.5 uS=64 (less one)
  OCR2B=7; //4 / 0.5 uS=8 (less one)
  TIFR2=bit(TOV2); //clear overflow flag
  TIMSK2=bit(TOIE2); //interrupt on overflow on TIMER2
  pinMode(HSYNCPIN, OUTPUT);
  pinMode(VSYNCPIN, OUTPUT);
  pinMode(COLORRED, OUTPUT);
  pinMode(COLORGREEN, OUTPUT);
  pinMode(COLORBLUE, OUTPUT);
  sei();
}

void clear(byte color) {
  register byte c=color;
  c&=3;
  register byte c0=(c*4) | c;
  c0|=c0*16;
  memset(vgaxfb, c0, VGAX_BSIZE);
}

void blitwmask(byte *src, byte *mask, byte swidth, byte sheight, char dx, char dy) {
  byte sh=sheight;
  byte *srcline=src;
  byte *maskline=mask;
  byte linesize=swidth>>2;
  if (swidth & 3)
      linesize++;
  while (sh--) {
    if (dy>-1 && dy<VGAX_HEIGHT) {
      byte sw=swidth, sx=0;
      char ldx=dx;
      while (sw--) {
        if (ldx>-1 && ldx<VGAX_WIDTH) {
          //get mask bit
          byte m=pgm_read_byte(maskline + (sx>>2));
          byte p=pgm_read_byte(srcline  + (sx>>2));
          //get sprite pixel and mask
          byte sbitpos=6-(sx & 3)*2;
          byte spixel=(p >> sbitpos) & 3;
          byte mpixel=(m >> sbitpos) & 3;
          //set framebuffer pixel with AND+OR blit
          byte *pfb=vgaxfb + dy*VGAX_BWIDTH + (ldx>>2);
          byte dbitpos=6-(ldx & 3)*2;
          *pfb &=(mpixel << dbitpos) | ~(3<<dbitpos);
          *pfb |=(spixel << dbitpos);
        }
        sx++;
        ldx++;
      }
    }
    srcline +=linesize;
    maskline+=linesize;
    dy++;
  }
}