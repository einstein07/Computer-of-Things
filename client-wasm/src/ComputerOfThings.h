 
#ifndef COMPUTER_OF_THINGS_H
#define COMPUTER_OF_THINGS_H
#include "workpackage_generated.h"
#include "request_generated.h"
        float add(float arg1, float arg2);
        std::vector<float> add(const workpackage::common::Matrix2D* a, const workpackage::common::Matrix2D* b);
        float subtract(float arg1, float arg2);
        std::vector<float> subtract(const workpackage::common::Matrix2D* a, const workpackage::common::Matrix2D* b);
        float mult(float arg1, float arg2);
        std::vector<float> mult(const workpackage::common::Matrix2D* a, const workpackage::common::Matrix2D* b);
        extern "C" {
        char* /*const workpackage::OperationResponse*/ processWorkPackages(/**const workpackage::OperationRequest* request_*/ char* data);
        }
        extern "C"{
        char* deserializeWorkpackage(const std::string & fileName);
        }
        extern "C"{
        int getResponseLength();
        }
#endif
