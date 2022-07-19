// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_REQUEST_WORKPACKAGE_REQUEST_H_
#define FLATBUFFERS_GENERATED_REQUEST_WORKPACKAGE_REQUEST_H_

#include "flatbuffers/flatbuffers.h"

#include "common_generated.h"

namespace workpackage {
namespace request {

struct BivariateScalarRequest;

struct BivariateMatrixRequest;

enum Request {
  Request_NONE = 0,
  Request_BivariateScalarRequest = 1,
  Request_BivariateMatrixRequest = 2,
  Request_MIN = Request_NONE,
  Request_MAX = Request_BivariateMatrixRequest
};

inline const Request (&EnumValuesRequest())[3] {
  static const Request values[] = {
    Request_NONE,
    Request_BivariateScalarRequest,
    Request_BivariateMatrixRequest
  };
  return values;
}

inline const char * const *EnumNamesRequest() {
  static const char * const names[] = {
    "NONE",
    "BivariateScalarRequest",
    "BivariateMatrixRequest",
    nullptr
  };
  return names;
}

inline const char *EnumNameRequest(Request e) {
  if (e < Request_NONE || e > Request_BivariateMatrixRequest) return "";
  const size_t index = static_cast<size_t>(e);
  return EnumNamesRequest()[index];
}

template<typename T> struct RequestTraits {
  static const Request enum_value = Request_NONE;
};

template<> struct RequestTraits<BivariateScalarRequest> {
  static const Request enum_value = Request_BivariateScalarRequest;
};

template<> struct RequestTraits<BivariateMatrixRequest> {
  static const Request enum_value = Request_BivariateMatrixRequest;
};

bool VerifyRequest(flatbuffers::Verifier &verifier, const void *obj, Request type);
bool VerifyRequestVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct BivariateScalarRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_A = 4,
    VT_B = 6
  };
  float a() const {
    return GetField<float>(VT_A, 0.0f);
  }
  float b() const {
    return GetField<float>(VT_B, 0.0f);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<float>(verifier, VT_A) &&
           VerifyField<float>(verifier, VT_B) &&
           verifier.EndTable();
  }
};

struct BivariateScalarRequestBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_a(float a) {
    fbb_.AddElement<float>(BivariateScalarRequest::VT_A, a, 0.0f);
  }
  void add_b(float b) {
    fbb_.AddElement<float>(BivariateScalarRequest::VT_B, b, 0.0f);
  }
  explicit BivariateScalarRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  BivariateScalarRequestBuilder &operator=(const BivariateScalarRequestBuilder &);
  flatbuffers::Offset<BivariateScalarRequest> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<BivariateScalarRequest>(end);
    return o;
  }
};

inline flatbuffers::Offset<BivariateScalarRequest> CreateBivariateScalarRequest(
    flatbuffers::FlatBufferBuilder &_fbb,
    float a = 0.0f,
    float b = 0.0f) {
  BivariateScalarRequestBuilder builder_(_fbb);
  builder_.add_b(b);
  builder_.add_a(a);
  return builder_.Finish();
}

struct BivariateMatrixRequest FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_A_TYPE = 4,
    VT_A = 6,
    VT_B_TYPE = 8,
    VT_B = 10
  };
  workpackage::common::Matrix a_type() const {
    return static_cast<workpackage::common::Matrix>(GetField<uint8_t>(VT_A_TYPE, 0));
  }
  const void *a() const {
    return GetPointer<const void *>(VT_A);
  }
  template<typename T> const T *a_as() const;
  const workpackage::common::Matrix2D *a_as_Matrix2D() const {
    return a_type() == workpackage::common::Matrix_Matrix2D ? static_cast<const workpackage::common::Matrix2D *>(a()) : nullptr;
  }
  const workpackage::common::Matrix3D *a_as_Matrix3D() const {
    return a_type() == workpackage::common::Matrix_Matrix3D ? static_cast<const workpackage::common::Matrix3D *>(a()) : nullptr;
  }
  const workpackage::common::MatrixND *a_as_MatrixND() const {
    return a_type() == workpackage::common::Matrix_MatrixND ? static_cast<const workpackage::common::MatrixND *>(a()) : nullptr;
  }
  workpackage::common::Matrix b_type() const {
    return static_cast<workpackage::common::Matrix>(GetField<uint8_t>(VT_B_TYPE, 0));
  }
  const void *b() const {
    return GetPointer<const void *>(VT_B);
  }
  template<typename T> const T *b_as() const;
  const workpackage::common::Matrix2D *b_as_Matrix2D() const {
    return b_type() == workpackage::common::Matrix_Matrix2D ? static_cast<const workpackage::common::Matrix2D *>(b()) : nullptr;
  }
  const workpackage::common::Matrix3D *b_as_Matrix3D() const {
    return b_type() == workpackage::common::Matrix_Matrix3D ? static_cast<const workpackage::common::Matrix3D *>(b()) : nullptr;
  }
  const workpackage::common::MatrixND *b_as_MatrixND() const {
    return b_type() == workpackage::common::Matrix_MatrixND ? static_cast<const workpackage::common::MatrixND *>(b()) : nullptr;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_A_TYPE) &&
           VerifyOffset(verifier, VT_A) &&
           VerifyMatrix(verifier, a(), a_type()) &&
           VerifyField<uint8_t>(verifier, VT_B_TYPE) &&
           VerifyOffset(verifier, VT_B) &&
           VerifyMatrix(verifier, b(), b_type()) &&
           verifier.EndTable();
  }
};

template<> inline const workpackage::common::Matrix2D *BivariateMatrixRequest::a_as<workpackage::common::Matrix2D>() const {
  return a_as_Matrix2D();
}

template<> inline const workpackage::common::Matrix3D *BivariateMatrixRequest::a_as<workpackage::common::Matrix3D>() const {
  return a_as_Matrix3D();
}

template<> inline const workpackage::common::MatrixND *BivariateMatrixRequest::a_as<workpackage::common::MatrixND>() const {
  return a_as_MatrixND();
}

template<> inline const workpackage::common::Matrix2D *BivariateMatrixRequest::b_as<workpackage::common::Matrix2D>() const {
  return b_as_Matrix2D();
}

template<> inline const workpackage::common::Matrix3D *BivariateMatrixRequest::b_as<workpackage::common::Matrix3D>() const {
  return b_as_Matrix3D();
}

template<> inline const workpackage::common::MatrixND *BivariateMatrixRequest::b_as<workpackage::common::MatrixND>() const {
  return b_as_MatrixND();
}

struct BivariateMatrixRequestBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_a_type(workpackage::common::Matrix a_type) {
    fbb_.AddElement<uint8_t>(BivariateMatrixRequest::VT_A_TYPE, static_cast<uint8_t>(a_type), 0);
  }
  void add_a(flatbuffers::Offset<void> a) {
    fbb_.AddOffset(BivariateMatrixRequest::VT_A, a);
  }
  void add_b_type(workpackage::common::Matrix b_type) {
    fbb_.AddElement<uint8_t>(BivariateMatrixRequest::VT_B_TYPE, static_cast<uint8_t>(b_type), 0);
  }
  void add_b(flatbuffers::Offset<void> b) {
    fbb_.AddOffset(BivariateMatrixRequest::VT_B, b);
  }
  explicit BivariateMatrixRequestBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  BivariateMatrixRequestBuilder &operator=(const BivariateMatrixRequestBuilder &);
  flatbuffers::Offset<BivariateMatrixRequest> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<BivariateMatrixRequest>(end);
    return o;
  }
};

inline flatbuffers::Offset<BivariateMatrixRequest> CreateBivariateMatrixRequest(
    flatbuffers::FlatBufferBuilder &_fbb,
    workpackage::common::Matrix a_type = workpackage::common::Matrix_NONE,
    flatbuffers::Offset<void> a = 0,
    workpackage::common::Matrix b_type = workpackage::common::Matrix_NONE,
    flatbuffers::Offset<void> b = 0) {
  BivariateMatrixRequestBuilder builder_(_fbb);
  builder_.add_b(b);
  builder_.add_a(a);
  builder_.add_b_type(b_type);
  builder_.add_a_type(a_type);
  return builder_.Finish();
}

inline bool VerifyRequest(flatbuffers::Verifier &verifier, const void *obj, Request type) {
  switch (type) {
    case Request_NONE: {
      return true;
    }
    case Request_BivariateScalarRequest: {
      auto ptr = reinterpret_cast<const BivariateScalarRequest *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Request_BivariateMatrixRequest: {
      auto ptr = reinterpret_cast<const BivariateMatrixRequest *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyRequestVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (!values || !types) return !values && !types;
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyRequest(
        verifier,  values->Get(i), types->GetEnum<Request>(i))) {
      return false;
    }
  }
  return true;
}

}  // namespace request
}  // namespace workpackage

#endif  // FLATBUFFERS_GENERATED_REQUEST_WORKPACKAGE_REQUEST_H_
