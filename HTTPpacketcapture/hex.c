#include "hex.h"

#define    ROW_LINE        16    // �޸� ��� �� ��




void hex(const void *vAddr, unsigned int print_line)
// Memory Status Display Function
/*******************************************************************************
���   : �μ��� �Ѱܹ��� �ּҷκ��� ROW_LINE�� ������ 1�ٷ� print_line�� ���� ��ŭ
ȭ�鿡 ���
�μ�   : ����� ����� �ִ� ���� �ּҰ�, �޸� ��½� ��� ���� ��
��ȯ��   : void
*******************************************************************************/
{
  unsigned char		*addr = (unsigned char *)vAddr;
  unsigned int		loop_temp   = 0;     // �ݺ����� ���� �ӽ� ���� ����
  unsigned char		memory_dump[ROW_LINE];     // ��ȯ�� �޸𸮰��� �ӽ÷� ����
  unsigned int num = 0;
  //if (0 == *addr)
  //{
//	  return;
  //}
 // else
  //{
	printf(" Address   ");         // ȭ�� ��� �ڸ� ǥ�ø� ���� ���
//  }
  
  while (loop_temp < ROW_LINE)       // Hex �κ� ��� (00 ~ 0F)
  {
    printf("%02X ", loop_temp++);
  }

  putchar(' ');        //�Ѱ� ���
  loop_temp = 0;

  while (loop_temp < ROW_LINE)       // ASCII �κ� ��� (0 ~ F)
  {
    printf("%X", loop_temp++);
  }

  putchar('\n');               //���� ���
  	
  while (0 < print_line)           // Data �κ� ��� ���� ����
  {
    loop_temp = 0;
    printf("0x%08x ",num);     // �޸� �ּ� ���
	num = num+16;
    while (1)                 // �޸� �о� ���� �� hex ��� ����
    {
      // �޸� �ּҿ� ��ġ�� ���� �迭�� ����
      *(memory_dump + loop_temp) = *addr;

      // �迭�� ����� �� ���
      printf("%02X ", *(memory_dump + loop_temp));

      ++loop_temp;
      ++addr;

      if (0 == (loop_temp % ROW_LINE))  // ROW_LINE���� ����Ͽ����� loop ����
      {
        break;
      }
      else
      {
      }
    }                   // �޸� �о� ���� �� hex ��� ��

    putchar(' ');
    loop_temp = 0;

    while (1)               // ASCII �κ� ��� ���� ����
    {
      if (0 == *(memory_dump + loop_temp))
      {
        putchar('.');         // �� ���� ��ġ
      }
      else if (32 > *(memory_dump + loop_temp))
      {
        putchar('*');         // ���� ���� ��ġ
      }
      else if (127 <= *(memory_dump + loop_temp))
      {
        putchar('*');         // �׷��� ���� ��ġ
      }
      else
      {
        putchar(*(memory_dump + loop_temp));
      }

      ++loop_temp;

      if (0 == (loop_temp % ROW_LINE))  // ROW_LINE���� ����Ͽ����� loop ����
      {
        break;
      }
      else
      {
      }
    }                   // ASCII �κ� ��� ���� ��

    putchar('\n');
    --print_line;
  }                     // Data ��� ���� ��

  putchar('\n');
}

