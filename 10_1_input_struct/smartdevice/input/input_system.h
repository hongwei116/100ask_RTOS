#ifndef __INPUT_SYSTEM_H
#define __INPUT_SYSTEM_H

#define TIME_T int
#define INTPU_BUF_LEN 1024

typedef enum
{    
	INPUT_EVENT_TYPE_KEY,
	INPUT_EVENT_TYPE_TOUCH,
	INPUT_EVENT_TYPE_NET,
	INPUT_EVENT_TYPE_STDIO
}INPUT_EVENT_TYPE;

typedef struct InputEvent {
	TIME_T time;
	INPUT_EVENT_TYPE eType;
	int iX;
	int iY;
	int iKey;
	int iPressure;
	char str[INTPU_BUF_LEN];
}InputEvent, *PInputEvent;

typedef struct InputDevice {
	char *name;
	int (*GetInputEvent)(PInputEvent ptInputEvent);
	int (*DeviceInit)(void);
	int (*DeviceExit)(void);
	struct InputDevice *pNext;
}InputDevice, *PInputDevice;


/**********************************************************************
 * �������ƣ� AddInputDevices
 * ���������� ע���������豸
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2021/09/24	     V1.0	  Τ��ɽ	      ����
 ***********************************************************************/
void AddInputDevices(void);


/**********************************************************************
 * �������ƣ� InitInputDevices
 * ���������� ��ʼ�����е������豸
 * ��������� ��
 * ��������� ��
 * �� �� ֵ�� ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2021/09/24	     V1.0	  Τ��ɽ	      ����
 ***********************************************************************/
void InitInputDevices(void);

/**********************************************************************
 * �������ƣ� InputDeviceRegister
 * ���������� ע��һ�������豸
 * ��������� ptInputDevice-�����豸
 * ��������� ��
 * �� �� ֵ�� ��
 * �޸�����        �汾��     �޸���	      �޸�����
 * -----------------------------------------------
 * 2021/09/24	     V1.0	  Τ��ɽ	      ����
 ***********************************************************************/
void InputDeviceRegister(PInputDevice ptInputDevice);


#endif /* __INPUT_SYSTEM_H */



