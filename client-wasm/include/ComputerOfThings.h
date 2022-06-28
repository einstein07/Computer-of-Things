 
#ifndef COMPUTER_OF_THINGS_H
#define COMPUTER_OF_THINGS_H
#include "workpackage_generated.h"
#include "request_generated.h"

        float add(float arg1, float arg2);
        float subtract(float arg1, float arg2);
        float mult(float arg1, float arg2);
        std::vector<float> mult(const workpackage::common::Matrix2D* a, const workpackage::common::Matrix2D* b);
        const workpackage::OperationResponse* process_work_packages(const workpackage::OperationRequest* request_);

#endif