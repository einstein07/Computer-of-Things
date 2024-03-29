// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_WORKPACKAGE_WORKPACKAGE_H_
#define FLATBUFFERS_GENERATED_WORKPACKAGE_WORKPACKAGE_H_

#include "flatbuffers/flatbuffers.h"

#include "common_generated.h"
#include "request_generated.h"
#include "response_generated.h"

namespace workpackage {

struct WorkpackageRequest;

struct WorkpackageResponse;

enum Operation {
  Operation_ADD = 0,
  Operation_SUBTRACT = 1,
  Operation_MULTIPLY = 2,
  Operation_MIN = Operation_ADD,
  Operation_MAX = Operation_MULTIPLY
};

inline const Operation (&EnumValuesOperation())[3] {
  static const Operation values[] = {
    Operation_ADD,
    Operation_SUBTRACT,
    Operation_MULTIPLY
  };
  return values;
}

inline const char * const *EnumNamesOperation() {
  static const char * const names[] = {
    "ADD",
    "SUBTRACT",
    "MULTIPLY",
    nullptr
  };
  return names;
}

inline const char *EnumNameOperation(Operation e) {
  if (e < Operation_ADD || e > Operation_MULTIPLY) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesOperation()[index];
}

struct WorkpackageRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ID = 4,
    VT_OP_TYPE = 6,
    VT_REQUEST_TYPE = 8,
    VT_REQUEST = 10
  };
  int64_t id() const {
    return GetField<int64_t>(VT_ID, 0);
  }
  Operation op_type() const {
    return static_cast<Operation>(GetField<uint16_t>(VT_OP_TYPE, 0));
  }
  workpackage::request::Request request_type() const {
    return static_cast<workpackage::request::Request>(GetField<uint8_t>(VT_REQUEST_TYPE, 0));
  }
  const void *request() const {
    return GetPointer<const void *>(VT_REQUEST);
  }
  template<typename T> const T *request_as() const;
  const workpackage::request::BivariateScalarRequest *request_as_BivariateScalarRequest() const {
    return request_type() == workpackage::request::Request_BivariateScalarRequest ? static_cast<const workpackage::request::BivariateScalarRequest *>(request()) : nullptr;
  }
  const workpackage::request::BivariateMatrixRequest *request_as_BivariateMatrixRequest() const {
    return request_type() == workpackage::request::Request_BivariateMatrixRequest ? static_cast<const workpackage::request::BivariateMatrixRequest *>(request()) : nullptr;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int64_t>(verifier, VT_ID) &&
           VerifyField<uint16_t>(verifier, VT_OP_TYPE) &&
           VerifyField<uint8_t>(verifier, VT_REQUEST_TYPE) &&
           VerifyOffset(verifier, VT_REQUEST) &&
           VerifyRequest(verifier, request(), request_type()) &&
           verifier.EndTable();
  }
};

template<> inline const workpackage::request::BivariateScalarRequest *WorkpackageRequest::request_as<workpackage::request::BivariateScalarRequest>() const {
  return request_as_BivariateScalarRequest();
}

template<> inline const workpackage::request::BivariateMatrixRequest *WorkpackageRequest::request_as<workpackage::request::BivariateMatrixRequest>() const {
  return request_as_BivariateMatrixRequest();
}

struct WorkpackageRequestBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(int64_t id) {
    fbb_.AddElement<int64_t>(WorkpackageRequest::VT_ID, id, 0);
  }
  void add_op_type(Operation op_type) {
    fbb_.AddElement<uint16_t>(WorkpackageRequest::VT_OP_TYPE, static_cast<uint16_t>(op_type), 0);
  }
  void add_request_type(workpackage::request::Request request_type) {
    fbb_.AddElement<uint8_t>(WorkpackageRequest::VT_REQUEST_TYPE, static_cast<uint8_t>(request_type), 0);
  }
  void add_request(flatbuffers::Offset<void> request) {
    fbb_.AddOffset(WorkpackageRequest::VT_REQUEST, request);
  }
  explicit WorkpackageRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  WorkpackageRequestBuilder &operator=(const WorkpackageRequestBuilder &);
  flatbuffers::Offset<WorkpackageRequest> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<WorkpackageRequest>(end);
    return o;
  }
};

inline flatbuffers::Offset<WorkpackageRequest> CreateWorkpackageRequest(
    flatbuffers::FlatBufferBuilder &_fbb,
    int64_t id = 0,
    Operation op_type = Operation_ADD,
    workpackage::request::Request request_type = workpackage::request::Request_NONE,
    flatbuffers::Offset<void> request = 0) {
  WorkpackageRequestBuilder builder_(_fbb);
  builder_.add_id(id);
  builder_.add_request(request);
  builder_.add_op_type(op_type);
  builder_.add_request_type(request_type);
  return builder_.Finish();
}

struct WorkpackageResponse FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ID = 4,
    VT_RESPONSE_TYPE = 6,
    VT_RESPONSE = 8
  };
  int64_t id() const {
    return GetField<int64_t>(VT_ID, 0);
  }
  workpackage::response::Reponse response_type() const {
    return static_cast<workpackage::response::Reponse>(GetField<uint8_t>(VT_RESPONSE_TYPE, 0));
  }
  const void *response() const {
    return GetPointer<const void *>(VT_RESPONSE);
  }
  template<typename T> const T *response_as() const;
  const workpackage::response::ScalarResponse *response_as_ScalarResponse() const {
    return response_type() == workpackage::response::Reponse_ScalarResponse ? static_cast<const workpackage::response::ScalarResponse *>(response()) : nullptr;
  }
  const workpackage::response::MatrixResponse *response_as_MatrixResponse() const {
    return response_type() == workpackage::response::Reponse_MatrixResponse ? static_cast<const workpackage::response::MatrixResponse *>(response()) : nullptr;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int64_t>(verifier, VT_ID) &&
           VerifyField<uint8_t>(verifier, VT_RESPONSE_TYPE) &&
           VerifyOffset(verifier, VT_RESPONSE) &&
           VerifyReponse(verifier, response(), response_type()) &&
           verifier.EndTable();
  }
};

template<> inline const workpackage::response::ScalarResponse *WorkpackageResponse::response_as<workpackage::response::ScalarResponse>() const {
  return response_as_ScalarResponse();
}

template<> inline const workpackage::response::MatrixResponse *WorkpackageResponse::response_as<workpackage::response::MatrixResponse>() const {
  return response_as_MatrixResponse();
}

struct WorkpackageResponseBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_id(int64_t id) {
    fbb_.AddElement<int64_t>(WorkpackageResponse::VT_ID, id, 0);
  }
  void add_response_type(workpackage::response::Reponse response_type) {
    fbb_.AddElement<uint8_t>(WorkpackageResponse::VT_RESPONSE_TYPE, static_cast<uint8_t>(response_type), 0);
  }
  void add_response(flatbuffers::Offset<void> response) {
    fbb_.AddOffset(WorkpackageResponse::VT_RESPONSE, response);
  }
  explicit WorkpackageResponseBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  WorkpackageResponseBuilder &operator=(const WorkpackageResponseBuilder &);
  flatbuffers::Offset<WorkpackageResponse> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<WorkpackageResponse>(end);
    return o;
  }
};

inline flatbuffers::Offset<WorkpackageResponse> CreateWorkpackageResponse(
    flatbuffers::FlatBufferBuilder &_fbb,
    int64_t id = 0,
    workpackage::response::Reponse response_type = workpackage::response::Reponse_NONE,
    flatbuffers::Offset<void> response = 0) {
  WorkpackageResponseBuilder builder_(_fbb);
  builder_.add_id(id);
  builder_.add_response(response);
  builder_.add_response_type(response_type);
  return builder_.Finish();
}

}  // namespace workpackage

#endif  // FLATBUFFERS_GENERATED_WORKPACKAGE_WORKPACKAGE_H_
