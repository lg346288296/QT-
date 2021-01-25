#ifndef HAT_AD_PCPT_INTERFACE_H_
#define HAT_AD_PCPT_INTERFACE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "HAT_AD_cType.h"


/* ���������� */
#define ERR_BASE									0x01000000
#define ERR_ALLOC_MEMORY_FAILED      				0x01000001			/* �����ڴ�ʧ�� */
#define ERR_PTR_IS_NULL    							0x01000002			/* ָ������Ϊ�� */
#define ERR_INVALID_PARAM							0x01000003			/* �����������ȷ */
#define ERR_NOT_INIT								0x01000004			/* ��Դδ��ʼ�� */
#define ERR_REPEAT_INIT    							0x01000005			/* �ظ���ʼ�� */
#define ERR_INVALID_HANDLE							0x01000006			/* ʹ�õľ����Ч */
#define ERR_EMPTY_STRING							0x01000007			/* �ַ�������Ϊ�� */
/* ��(int��) */
typedef struct HAT_OUT_POINT_I_T_
{
    INT x;
    INT y;
} HAT_OUT_POINT_I;

/* ��(float��) */
typedef struct HAT_OUT_POINT_F_T_
{
    FLOAT32 x;
    FLOAT32 y;
}HAT_OUT_POINT_F;

/* 3D��(float��) */
typedef struct HAT_OUT_POINT_3D_F_T_
{
    FLOAT32 x;
    FLOAT32 y;
    FLOAT32 z;
}HAT_OUT_POINT_3D_F;

typedef enum HAT_OUT_ETH_D_TYPE_E_
{
    ETH_D_TYPE_HEART			= 1,
    ETH_D_TYPE_LOC_FUSION		= 2,
    ETH_D_TYPE_PCPT_FREESPACE	= 3,
    ETH_D_TYPE_PCPT_BARRIER		= 4,
    ETH_D_TYPE_PCPT_PSD			= 5,
    ETH_D_TYPE_GLOBALP_PATH     = 6,
}HAT_OUT_ETH_D_TYPE;

typedef struct _HAT_MDL_ETH_MSG_INFO_
{
#define	HAT_ETH_MSG_TYPE_HD	(0)
	UINT 	magic;
	UINT 	msg_len;			/* message length */
	UINT16  type;			/* ethernet data type HAT_OUT_ETH_D_TYPE */
	UINT16 	dev_id;			/* device id */
	UINT8   cpr_f;			/* compress flag */
	UINT8   res[2];
	INT8 	check;
}HAT_MDL_ETH_MSG_INFO; /*  16B   */

typedef struct
{
    short year;
    short month;
    short dayOfWeek;        /*0:������-6:������*/
    short day;
    short hour;
    short minute;
    short second;
    short milliSecond;
} DATE_TIME;
typedef struct HAT_OUT_PCPT_HEADER_T_
{
	UINT32 magic;	   		/* magic */
	UINT32 time_ms;			/* system relative time,ms */
	UINT32 frame_num;    	/* frame num */
    UINT32 data_length; 	//* data length */
    DATE_TIME  time_abs;		/* system absolute time */
}HAT_OUT_PCPT_HEADER;	/*32B*/

typedef enum HAT_OUT_OBJ_TYPE_E_
{
    HAT_OUT_OBJ_UNKNOWN              = 0,         //δ֪
    HAT_OUT_OBJ_NEGATIVE             = 0x01,      //��ЧĿ��
    HAT_OUT_OBJ_LARGE_VEHICLE        = 0x10,      //��
    HAT_OUT_OBJ_SMALL_VEHICLE        = 0x20,      //С��
    HAT_OUT_OBJ_MOTOR                = 0x30,      //Ħ�г�
    HAT_OUT_OBJ_HUMAN                = 0x40,      //����(�����г�)    
    HAT_OUT_OBJ_NON_VEHICLE          = 0x50,      //�����ֳ�
    HAT_OUT_OBJ_TWO_WHEEL            = 0x60,      //���ֳ�
    HAT_OUT_OBJ_THREE_WHEEL          = 0x70,      //���ֳ�  
	HAT_OUT_OBJ_FACE                 = 0x80,      //����
	HAT_OUT_OBJ_CONE                 = 0x90,      //���Ƕ�
	HAT_OUT_OBJ_BUS                  = 0x100,     //����
    HAT_OUT_OBJ_TRUCK                = 0x110,     //����
    HAT_OUT_OBJ_SMOG                 = 0x120,     //����
    HAT_OUT_OBJ_FLAME                = 0x130,     //����
    HAT_OUT_OBJ_BANNER               = 0x140,     //����
    HAT_OUT_OBJ_BOOTH                = 0x150,     //̯λ
    HAT_OUT_OBJ_HESH                 = 0x160,     //ͷ��
	HAT_OUT_OBJ_HEAD                 = 0x170,     //��ͷ

	HAT_OUT_OBJ_TRAFFICSIGN          = 0x200,     //��ͨ��־���������ٱ�־�����ر�־��
	HAT_OUT_OBJ_TRAFFICLIGHT         = 0x201,     //��ͨ��
	HAT_OUT_OBJ_LANE                 = 0x202,     //������
	HAT_OUT_OBJ_ROADEDGE             = 0x203,     //·��
	HAT_OUT_OBJ_ROADMARKING          = 0x204,     //·���־
	HAT_OUT_OBJ_WHEEL                = 0x205,     //����
	HAT_OUT_OBJ_VEHICLE_HEAD   		= 0x206,     //��ͷ
    HAT_OUT_OBJ_VEHICLE_TAIL   		= 0x207,     //��β
    HAT_OUT_OBJ_VEHICLE_FRONT_FACE   = 0x208,     //��ǰ��
    HAT_OUT_OBJ_VEHICLE_BACK_FACE    = 0x209,     //������
    HAT_OUT_OBJ_PLATE				= 0x20A,     //����
    HAT_OUT_OBJ_CAR_WINDOW	        = 0x20B,     //����
    
    HAT_OUT_OBJ_ROAD                 = 0x20C,     // ·��
	HAT_OUT_OBJ_ZEBRA                = 0x20D,     // ������
	HAT_OUT_OBJ_GENERAL              = 0x20E,     // ͨ���ϰ���
    HAT_OUT_OBJ_RADAR                = 0x250,     // �״�-�ϰ���
    HAT_OUT_OBJ_PSD                	= 0x251,     // ��λ��
    
	HAT_OUT_OBJ_AIRCRAFT             = 0x301,     // �ɻ�
	HAT_OUT_OBJ_UVA                  = 0x302,     // ���˻�
    HAT_OUT_OBJ_SHIP                 = 0x303,     // ����

} HAT_OUT_OBJ_TYPE;

typedef enum HAT_LOC_SRC_E_
{
	HAT_LOC_SRC_FUSION       = 1,           //��϶�λ
	HAT_LOC_SRC_DR           = 2,           //��λ����
	HAT_LOC_SRC_DR_FOR_LIDAR = 3,           //�ṩ�����ⶨλģ��ĺ�λ����
	HAT_LOC_SRC_END          = 0xFFFFFFFF   //ö�ٽ���ֵ
}HAT_LOC_SRC;

/* fusion location */
typedef struct HAT_OUT_LOC_FUSION_T_
{
    HAT_LOC_SRC      			loc_src;                   		 //������λ��Ϣ��Դ
    UINT                        sys_time_ms;                     //ϵͳʱ�䣬����
    DOUBLE                      pos_n[3];                        //���������췽���λ�� Pe,Pn,Pu m
    DOUBLE                      vel_n[3];                        //���������췽����ٶ� Ve,Vn,Vu m/s
    DOUBLE                      att_n[3];                        //����ǡ������ǡ������ roll,pitch,yaw rad
    DOUBLE                      vel_b[3];                        //�ҡ�ǰ���Ϸ�����ٶ� vx,vy,vz,m/s
    DOUBLE                      acc_b[3];                        //�ҡ�ǰ���Ϸ���ļ��ٶ� ax,ay,az,m/s^2
    DOUBLE                      wcc_b[3];                        //�ҡ�ǰ���Ϸ���Ľ��ٶ� wx,wy,wz,rad/s
    UINT                        flag;                            //��־λ
    UINT8                       res[4];                          //Ԥ��λ
}HAT_OUT_LOC_FUSION;	/* 160B */


/* fusion location data*/
typedef struct HAT_OUT_LOC_FUSION_DATA_T_
{
#define	LOC_FUSION_MAX_UNM	(5)
	HAT_OUT_PCPT_HEADER		header;		/* header */
	UINT					data_num;
	UINT8					res[4];
	HAT_OUT_LOC_FUSION	 	loc_fusion[LOC_FUSION_MAX_UNM];	/* fusion location */
}HAT_OUT_LOC_FUSION_DATA;

/* grid map param*/
typedef struct HAT_OUT_GRID_MAP_PARAM_T_
{
	UINT               n_row;	//դ��ͼ�������ظ���
	UINT               n_col;	//դ��ͼ�������ظ���
	FLOAT              step_row;//դ��ͼ������������ߴ磬��λm
	FLOAT              step_col;//դ��ͼ�������غ���ߴ磬��λm
	FLOAT              row_min;	//������С���룬��λm
	FLOAT              col_min;	//������С���룬��λm
}HAT_OUT_GRID_MAP_PARAM;	/* 24B */

/* perception freespace */
typedef struct HAT_OUT_FREESPACE_T_
{
#define HAT_OUT_FREESPACE_MAX_COUNT	(480*640)
	HAT_OUT_GRID_MAP_PARAM	param;//դ��ͼ����
	UINT					validFlag;//��Ч�� 0-��Ч��1-��Ч
	UINT					disSource;//�����Դ(�Ӿ�����������
	INT8					data[HAT_OUT_FREESPACE_MAX_COUNT];//դ��ͼ���� 
}HAT_OUT_FREESPACE;	/* 307232B */

/* perception freespace boundary */
typedef struct HAT_OUT_FREESPACE_BOUNDARY_T_
{
#define HAT_OUT_FS_BOUNDARY_POINT_MAX_NUM	(512)
	UINT                point_num;
	FLOAT              	step_x;	//��λm
	FLOAT              	step_y;	//��λm

	UINT8				res[4];
	HAT_OUT_POINT_I		point[HAT_OUT_FS_BOUNDARY_POINT_MAX_NUM];
} HAT_OUT_FREESPACE_BOUNDARY; /* 4112B */

/* perception freespace information */
typedef struct HAT_AD_FREESPACE_RESULT_T_
{	
	HAT_OUT_FREESPACE			fs;				/* free space */
	HAT_OUT_FREESPACE_BOUNDARY	fs_boundary;	/* free space boundary */
}HAT_OUT_FREESPACE_INF;

/* perception freespace data*/
typedef struct HAT_OUT_FREESPACE_DATA_T_
{
	HAT_OUT_PCPT_HEADER		header;		/* header */
	HAT_OUT_FREESPACE_INF 	freespace;	/* perception freespace */
}HAT_OUT_FREESPACE_DATA;

/* perception barrier */
typedef struct HAT_OUT_PCPT_BARRIER_T_
{
	INT32  id;					/* �ϰ���ID */
	HAT_OUT_OBJ_TYPE   type;	/* �ϰ�������,��ö�ٶ���*/
	UINT8  motion;			 	/* �ϰ���״̬,0-��ֹ,1-�˶� */
	UINT8  conf;				 //���Ŷ�
	UINT8  cut_status;       	 /* Ŀ������״̬:==0δ֪ ==1�ڱ�����  ==2���ڱ����� ==3 CutIn ==4 Cutout ==5PressLine*/
	UINT8  res[13];				 /* Ԥ�� */
	FLOAT32   length;		 	/* �ϰ��ﳤ��,��λm */
	FLOAT32   width; 		 	/* �ϰ�����,��λm */
	HAT_OUT_POINT_F vel_rel;	 /* Ŀ������ٶȣ���λm/s*/
	HAT_OUT_POINT_F coord[4];	 //����ϵ����ͼλ��,��λm
	FLOAT32	  u_min;			 //ͼ��Ŀ�������С���أ���һ����
	FLOAT32	  v_min;			 //ͼ��Ŀ��������أ���һ����
	FLOAT32	  img_width; 		 //ͼ��Ŀ������ؿ�ȣ���һ����
	FLOAT32	  img_height;		 //ͼ��Ŀ������ظ߶ȣ���һ����
}HAT_OUT_PCPT_BARRIER;	/* 88B */

/* perception barrier data*/
typedef struct HAT_OUT_PCPT_BARRIER_DATA_T_
{
#define OBJ_MAX_NUM	(128)
	HAT_OUT_PCPT_HEADER		header;					/* header */
	UINT					data_num;
	UINT8					res[4];
	HAT_OUT_PCPT_BARRIER 	pcpt_obj[OBJ_MAX_NUM];	/* perception barrier */
}HAT_OUT_PCPT_BARRIER_DATA;

/* perception PSD */
typedef struct HAT_OUT_PCPT_PSD_T_
{
	INT32  				id;				/* �ϰ���ID */
	HAT_OUT_OBJ_TYPE	type;			/* �ϰ�������,��ö�ٶ���*/
	UINT8  				conf;			/* confidence */
	UINT8  				res[15];		/* reserve */
	HAT_OUT_POINT_F		coord[4];	 	//����ϵ����ͼλ��,��λm
}HAT_OUT_PCPT_PSD;	/* 56B */

/* perception PSD data*/
typedef struct HAT_OUT_PCPT_PSD_DATA_T_
{
#define PSD_MAX_NUM	(64)
	HAT_OUT_PCPT_HEADER		header;					/* header */
	UINT					data_num;
	UINT8					res[4];
	HAT_OUT_PCPT_PSD 		pcpt_psd[PSD_MAX_NUM];	/* perception PSD */
}HAT_OUT_PCPT_PSD_DATA;

typedef struct HAT_OUT_GLOBAL_PATH_T_
{
#define GLOBAL_PATH_POINT_MAX_NUM	(2048)
	UINT32  point_num;			/* ·������ */
	UINT8	res[36];			/* ����λ */
	HAT_OUT_POINT_3D_F	point[GLOBAL_PATH_POINT_MAX_NUM];		/* ·����*/
}HAT_OUT_GLOBAL_PATH;	/* 24616B */

/* global path data*/
typedef struct HAT_OUT_GLOBAL_PATH_DATA_T_
{
    HAT_OUT_PCPT_HEADER 	header; 				/* header */
    HAT_OUT_GLOBAL_PATH		global_path;			/* global path */
}HAT_OUT_GLOBAL_PATH_DATA;


#ifdef __cplusplus
}
#endif

#endif
