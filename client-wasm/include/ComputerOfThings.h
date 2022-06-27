 
#ifndef COMPUTER_OF_THINGS_H
#define COMPUTER_OF_THINGS_H
#include "workpackage_generated.h"
#include "request_generated.h"

        long requestId_;
        workpackage::Operation operation_;

        float add(float arg1, float arg2);
        float subtract(float arg1, float arg2);
        std::vector<flatbuffers::Offset<float>> mult(const workpackage::common::Matrix2D* a, const workpackage::common::Matrix2D* b);
        uint8_t* process_work_packages(workpackage::OperationRequest* request);

#endif