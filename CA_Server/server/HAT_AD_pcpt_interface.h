#ifndef HAT_AD_PCPT_INTERFACE_H_
#define HAT_AD_PCPT_INTERFACE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "HAT_AD_cType.h"


/* 公共错误码 */
#define ERR_BASE									0x01000000
#define ERR_ALLOC_MEMORY_FAILED      				0x01000001			/* 申请内存失败 */
#define ERR_PTR_IS_NULL    							0x01000002			/* 指针内容为空 */
#define ERR_INVALID_PARAM							0x01000003			/* 输入参数不正确 */
#define ERR_NOT_INIT								0x01000004			/* 资源未初始化 */
#define ERR_REPEAT_INIT    							0x01000005			/* 重复初始化 */
#define ERR_INVALID_HANDLE							0x01000006			/* 使用的句柄无效 */
#define ERR_EMPTY_STRING							0x01000007			/* 字符串内容为空 */
/* 点(int型) */
typedef struct HAT_OUT_POINT_I_T_
{
    INT x;
    INT y;
} HAT_OUT_POINT_I;

/* 点(float型) */
typedef struct HAT_OUT_POINT_F_T_
{
    FLOAT32 x;
    FLOAT32 y;
}HAT_OUT_POINT_F;

/* 3D点(float型) */
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
    short dayOfWeek;        /*0:星期日-6:星期六*/
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
    HAT_OUT_OBJ_UNKNOWN              = 0,         //未知
    HAT_OUT_OBJ_NEGATIVE             = 0x01,      //无效目标
    HAT_OUT_OBJ_LARGE_VEHICLE        = 0x10,      //大车
    HAT_OUT_OBJ_SMALL_VEHICLE        = 0x20,      //小车
    HAT_OUT_OBJ_MOTOR                = 0x30,      //摩托车
    HAT_OUT_OBJ_HUMAN                = 0x40,      //行人(或自行车)    
    HAT_OUT_OBJ_NON_VEHICLE          = 0x50,      //非四轮车
    HAT_OUT_OBJ_TWO_WHEEL            = 0x60,      //二轮车
    HAT_OUT_OBJ_THREE_WHEEL          = 0x70,      //三轮车  
	HAT_OUT_OBJ_FACE                 = 0x80,      //人脸
	HAT_OUT_OBJ_CONE                 = 0x90,      //三角堆
	HAT_OUT_OBJ_BUS                  = 0x100,     //公交
    HAT_OUT_OBJ_TRUCK                = 0x110,     //货车
    HAT_OUT_OBJ_SMOG                 = 0x120,     //烟雾
    HAT_OUT_OBJ_FLAME                = 0x130,     //火灾
    HAT_OUT_OBJ_BANNER               = 0x140,     //条幅
    HAT_OUT_OBJ_BOOTH                = 0x150,     //摊位
    HAT_OUT_OBJ_HESH                 = 0x160,     //头肩
	HAT_OUT_OBJ_HEAD                 = 0x170,     //人头

	HAT_OUT_OBJ_TRAFFICSIGN          = 0x200,     //交通标志，包括限速标志、限重标志等
	HAT_OUT_OBJ_TRAFFICLIGHT         = 0x201,     //交通灯
	HAT_OUT_OBJ_LANE                 = 0x202,     //车道线
	HAT_OUT_OBJ_ROADEDGE             = 0x203,     //路沿
	HAT_OUT_OBJ_ROADMARKING          = 0x204,     //路面标志
	HAT_OUT_OBJ_WHEEL                = 0x205,     //车轮
	HAT_OUT_OBJ_VEHICLE_HEAD   		= 0x206,     //车头
    HAT_OUT_OBJ_VEHICLE_TAIL   		= 0x207,     //车尾
    HAT_OUT_OBJ_VEHICLE_FRONT_FACE   = 0x208,     //车前脸
    HAT_OUT_OBJ_VEHICLE_BACK_FACE    = 0x209,     //车后脸
    HAT_OUT_OBJ_PLATE				= 0x20A,     //车牌
    HAT_OUT_OBJ_CAR_WINDOW	        = 0x20B,     //车窗
    
    HAT_OUT_OBJ_ROAD                 = 0x20C,     // 路面
	HAT_OUT_OBJ_ZEBRA                = 0x20D,     // 斑马线
	HAT_OUT_OBJ_GENERAL              = 0x20E,     // 通用障碍物
    HAT_OUT_OBJ_RADAR                = 0x250,     // 雷达-障碍物
    HAT_OUT_OBJ_PSD                	= 0x251,     // 车位框
    
	HAT_OUT_OBJ_AIRCRAFT             = 0x301,     // 飞机
	HAT_OUT_OBJ_UVA                  = 0x302,     // 无人机
    HAT_OUT_OBJ_SHIP                 = 0x303,     // 船舶

} HAT_OUT_OBJ_TYPE;

typedef enum HAT_LOC_SRC_E_
{
	HAT_LOC_SRC_FUSION       = 1,           //组合定位
	HAT_LOC_SRC_DR           = 2,           //航位推算
	HAT_LOC_SRC_DR_FOR_LIDAR = 3,           //提供给激光定位模块的航位推算
	HAT_LOC_SRC_END          = 0xFFFFFFFF   //枚举结束值
}HAT_LOC_SRC;

/* fusion location */
typedef struct HAT_OUT_LOC_FUSION_T_
{
    HAT_LOC_SRC      			loc_src;                   		 //车辆定位信息来源
    UINT                        sys_time_ms;                     //系统时间，毫秒
    DOUBLE                      pos_n[3];                        //东、北、天方向的位置 Pe,Pn,Pu m
    DOUBLE                      vel_n[3];                        //东、北、天方向的速度 Ve,Vn,Vu m/s
    DOUBLE                      att_n[3];                        //横滚角、俯仰角、航向角 roll,pitch,yaw rad
    DOUBLE                      vel_b[3];                        //右、前、上方向的速度 vx,vy,vz,m/s
    DOUBLE                      acc_b[3];                        //右、前、上方向的加速度 ax,ay,az,m/s^2
    DOUBLE                      wcc_b[3];                        //右、前、上方向的角速度 wx,wy,wz,rad/s
    UINT                        flag;                            //标志位
    UINT8                       res[4];                          //预留位
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
	UINT               n_row;	//栅格图纵向像素个数
	UINT               n_col;	//栅格图横向像素个数
	FLOAT              step_row;//栅格图单个像素纵向尺寸，单位m
	FLOAT              step_col;//栅格图单个像素横向尺寸，单位m
	FLOAT              row_min;	//纵向最小距离，单位m
	FLOAT              col_min;	//横向最小距离，单位m
}HAT_OUT_GRID_MAP_PARAM;	/* 24B */

/* perception freespace */
typedef struct HAT_OUT_FREESPACE_T_
{
#define HAT_OUT_FREESPACE_MAX_COUNT	(480*640)
	HAT_OUT_GRID_MAP_PARAM	param;//栅格图参数
	UINT					validFlag;//有效性 0-无效，1-有效
	UINT					disSource;//测距来源(视觉、超声波）
	INT8					data[HAT_OUT_FREESPACE_MAX_COUNT];//栅格图数据 
}HAT_OUT_FREESPACE;	/* 307232B */

/* perception freespace boundary */
typedef struct HAT_OUT_FREESPACE_BOUNDARY_T_
{
#define HAT_OUT_FS_BOUNDARY_POINT_MAX_NUM	(512)
	UINT                point_num;
	FLOAT              	step_x;	//单位m
	FLOAT              	step_y;	//单位m

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
	INT32  id;					/* 障碍物ID */
	HAT_OUT_OBJ_TYPE   type;	/* 障碍物类型,见枚举定义*/
	UINT8  motion;			 	/* 障碍物状态,0-静止,1-运动 */
	UINT8  conf;				 //置信度
	UINT8  cut_status;       	 /* 目标切入状态:==0未知 ==1在本车道  ==2不在本车道 ==3 CutIn ==4 Cutout ==5PressLine*/
	UINT8  res[13];				 /* 预留 */
	FLOAT32   length;		 	/* 障碍物长度,单位m */
	FLOAT32   width; 		 	/* 障碍物宽度,单位m */
	HAT_OUT_POINT_F vel_rel;	 /* 目标相对速度，单位m/s*/
	HAT_OUT_POINT_F coord[4];	 //车体系俯视图位置,单位m
	FLOAT32	  u_min;			 //图像目标框左最小像素（归一化）
	FLOAT32	  v_min;			 //图像目标框上像素（归一化）
	FLOAT32	  img_width; 		 //图像目标框像素宽度（归一化）
	FLOAT32	  img_height;		 //图像目标框像素高度（归一化）
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
	INT32  				id;				/* 障碍物ID */
	HAT_OUT_OBJ_TYPE	type;			/* 障碍物类型,见枚举定义*/
	UINT8  				conf;			/* confidence */
	UINT8  				res[15];		/* reserve */
	HAT_OUT_POINT_F		coord[4];	 	//车体系俯视图位置,单位m
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
	UINT32  point_num;			/* 路径点数 */
	UINT8	res[36];			/* 保留位 */
	HAT_OUT_POINT_3D_F	point[GLOBAL_PATH_POINT_MAX_NUM];		/* 路径点*/
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
