#include "hex.h"

#define    ROW_LINE        16    // 메모리 출력 열 수




void hex(const void *vAddr, unsigned int print_line)
// Memory Status Display Function
/*******************************************************************************
기능   : 인수로 넘겨받은 주소로부터 ROW_LINE개 단위를 1줄로 print_line의 숫자 만큼
화면에 출력
인수   : 출력할 대상이 있는 곳의 주소값, 메모리 출력시 출력 라인 수
반환값   : void
*******************************************************************************/
{
  unsigned char		*addr = (unsigned char *)vAddr;
  unsigned int		loop_temp   = 0;     // 반복문을 위한 임시 변수 선언
  unsigned char		memory_dump[ROW_LINE];     // 반환된 메모리값을 임시로 저장
  unsigned int num = 0;
  //if (0 == *addr)
  //{
//	  return;
  //}
 // else
  //{
	printf(" Address   ");         // 화면 상단 자리 표시를 위한 출력
//  }
  
  while (loop_temp < ROW_LINE)       // Hex 부분 출력 (00 ~ 0F)
  {
    printf("%02X ", loop_temp++);
  }

  putchar(' ');        //한간 띄움
  loop_temp = 0;

  while (loop_temp < ROW_LINE)       // ASCII 부분 출력 (0 ~ F)
  {
    printf("%X", loop_temp++);
  }

  putchar('\n');               //한줄 띄움
  	
  while (0 < print_line)           // Data 부분 출력 루프 시작
  {
    loop_temp = 0;
    printf("0x%08x ",num);     // 메모리 주소 출력
	num = num+16;
    while (1)                 // 메모리 읽어 오기 및 hex 출력 시작
    {
      // 메모리 주소에 위치한 값을 배열에 저장
      *(memory_dump + loop_temp) = *addr;

      // 배열에 저장된 값 출력
      printf("%02X ", *(memory_dump + loop_temp));

      ++loop_temp;
      ++addr;

      if (0 == (loop_temp % ROW_LINE))  // ROW_LINE개를 출력하였으면 loop 종료
      {
        break;
      }
      else
      {
      }
    }                   // 메모리 읽어 오기 및 hex 출력 끝

    putchar(' ');
    loop_temp = 0;

    while (1)               // ASCII 부분 출력 루프 시작
    {
      if (0 == *(memory_dump + loop_temp))
      {
        putchar('.');         // 널 문자 대치
      }
      else if (32 > *(memory_dump + loop_temp))
      {
        putchar('*');         // 제어 문자 대치
      }
      else if (127 <= *(memory_dump + loop_temp))
      {
        putchar('*');         // 그래픽 문자 대치
      }
      else
      {
        putchar(*(memory_dump + loop_temp));
      }

      ++loop_temp;

      if (0 == (loop_temp % ROW_LINE))  // ROW_LINE개를 출력하였으면 loop 종료
      {
        break;
      }
      else
      {
      }
    }                   // ASCII 부분 출력 루프 끝

    putchar('\n');
    --print_line;
  }                     // Data 출력 루프 끝

  putchar('\n');
}

