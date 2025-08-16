#include "can.h"
#include "main.h"

CAN_RxHeaderTypeDef CAN_RxHeader;
CAN_TxHeaderTypeDef CAN_TxHeader;
uint8_t buffer[9] = {0};
uint32_t TxMailbox = 0;

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef* hcan){
    if (HAL_CAN_GetRxMessage(hcan,CAN_RX_FIFO0,&CAN_RxHeader,buffer) != HAL_OK){
        Error_Handler();
    }
    if(hcan->Instance == CAN1){
        printf("GetCAN1Msg0\n");
    }
		if(hcan->Instance == CAN2){
        printf("GetCAN2Msg0\n");
    }
}

void HAL_CAN_RxFifo1MsgPendingCallback(CAN_HandleTypeDef* hcan){
    if (HAL_CAN_GetRxMessage(hcan,CAN_RX_FIFO1,&CAN_RxHeader,buffer) != HAL_OK){
        Error_Handler();
    }
		if(hcan->Instance == CAN1){
        printf("GetCAN1Msg1\n");
    }
    if(hcan->Instance == CAN2){
        printf("GetCAN2Msg1\n");
    }
}