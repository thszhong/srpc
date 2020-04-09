// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: echo.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_echo_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_echo_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_echo_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_echo_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_echo_2eproto;
namespace echo {
class EchoRequest;
class EchoRequestDefaultTypeInternal;
extern EchoRequestDefaultTypeInternal _EchoRequest_default_instance_;
class EchoResponse;
class EchoResponseDefaultTypeInternal;
extern EchoResponseDefaultTypeInternal _EchoResponse_default_instance_;
}  // namespace echo
PROTOBUF_NAMESPACE_OPEN
template<> ::echo::EchoRequest* Arena::CreateMaybeMessage<::echo::EchoRequest>(Arena*);
template<> ::echo::EchoResponse* Arena::CreateMaybeMessage<::echo::EchoResponse>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace echo {

// ===================================================================

class EchoRequest PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:echo.EchoRequest) */ {
 public:
  inline EchoRequest() : EchoRequest(nullptr) {};
  virtual ~EchoRequest();

  EchoRequest(const EchoRequest& from);
  EchoRequest(EchoRequest&& from) noexcept
    : EchoRequest() {
    *this = ::std::move(from);
  }

  inline EchoRequest& operator=(const EchoRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline EchoRequest& operator=(EchoRequest&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const EchoRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const EchoRequest* internal_default_instance() {
    return reinterpret_cast<const EchoRequest*>(
               &_EchoRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(EchoRequest& a, EchoRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(EchoRequest* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(EchoRequest* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline EchoRequest* New() const final {
    return CreateMaybeMessage<EchoRequest>(nullptr);
  }

  EchoRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<EchoRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const EchoRequest& from);
  void MergeFrom(const EchoRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(EchoRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "echo.EchoRequest";
  }
  protected:
  explicit EchoRequest(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_echo_2eproto);
    return ::descriptor_table_echo_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kDataFieldNumber = 1,
  };
  // repeated int32 data = 1;
  int data_size() const;
  private:
  int _internal_data_size() const;
  public:
  void clear_data();
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_data(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      _internal_data() const;
  void _internal_add_data(::PROTOBUF_NAMESPACE_ID::int32 value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      _internal_mutable_data();
  public:
  ::PROTOBUF_NAMESPACE_ID::int32 data(int index) const;
  void set_data(int index, ::PROTOBUF_NAMESPACE_ID::int32 value);
  void add_data(::PROTOBUF_NAMESPACE_ID::int32 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      data() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      mutable_data();

  // @@protoc_insertion_point(class_scope:echo.EchoRequest)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 > data_;
  mutable std::atomic<int> _data_cached_byte_size_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_echo_2eproto;
};
// -------------------------------------------------------------------

class EchoResponse PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:echo.EchoResponse) */ {
 public:
  inline EchoResponse() : EchoResponse(nullptr) {};
  virtual ~EchoResponse();

  EchoResponse(const EchoResponse& from);
  EchoResponse(EchoResponse&& from) noexcept
    : EchoResponse() {
    *this = ::std::move(from);
  }

  inline EchoResponse& operator=(const EchoResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline EchoResponse& operator=(EchoResponse&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const EchoResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const EchoResponse* internal_default_instance() {
    return reinterpret_cast<const EchoResponse*>(
               &_EchoResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(EchoResponse& a, EchoResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(EchoResponse* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(EchoResponse* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline EchoResponse* New() const final {
    return CreateMaybeMessage<EchoResponse>(nullptr);
  }

  EchoResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<EchoResponse>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const EchoResponse& from);
  void MergeFrom(const EchoResponse& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(EchoResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "echo.EchoResponse";
  }
  protected:
  explicit EchoResponse(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_echo_2eproto);
    return ::descriptor_table_echo_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kSortedDataFieldNumber = 1,
    kSumFieldNumber = 2,
    kIndexFieldNumber = 3,
  };
  // repeated int32 sorted_data = 1;
  int sorted_data_size() const;
  private:
  int _internal_sorted_data_size() const;
  public:
  void clear_sorted_data();
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_sorted_data(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      _internal_sorted_data() const;
  void _internal_add_sorted_data(::PROTOBUF_NAMESPACE_ID::int32 value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      _internal_mutable_sorted_data();
  public:
  ::PROTOBUF_NAMESPACE_ID::int32 sorted_data(int index) const;
  void set_sorted_data(int index, ::PROTOBUF_NAMESPACE_ID::int32 value);
  void add_sorted_data(::PROTOBUF_NAMESPACE_ID::int32 value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
      sorted_data() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
      mutable_sorted_data();

  // int32 sum = 2;
  void clear_sum();
  ::PROTOBUF_NAMESPACE_ID::int32 sum() const;
  void set_sum(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_sum() const;
  void _internal_set_sum(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // int32 index = 3;
  void clear_index();
  ::PROTOBUF_NAMESPACE_ID::int32 index() const;
  void set_index(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_index() const;
  void _internal_set_index(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:echo.EchoResponse)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 > sorted_data_;
  mutable std::atomic<int> _sorted_data_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::int32 sum_;
  ::PROTOBUF_NAMESPACE_ID::int32 index_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_echo_2eproto;
};
// ===================================================================

class EchoService_Stub;

class EchoService : public ::PROTOBUF_NAMESPACE_ID::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline EchoService() {};
 public:
  virtual ~EchoService();

  typedef EchoService_Stub Stub;

  static const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* descriptor();

  virtual void Get(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::echo::EchoRequest* request,
                       ::echo::EchoResponse* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                  ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                  const ::PROTOBUF_NAMESPACE_ID::Message* request,
                  ::PROTOBUF_NAMESPACE_ID::Message* response,
                  ::google::protobuf::Closure* done);
  const ::PROTOBUF_NAMESPACE_ID::Message& GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;
  const ::PROTOBUF_NAMESPACE_ID::Message& GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(EchoService);
};

class EchoService_Stub : public EchoService {
 public:
  EchoService_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel);
  EchoService_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
                   ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership);
  ~EchoService_Stub();

  inline ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel() { return channel_; }

  // implements EchoService ------------------------------------------

  void Get(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::echo::EchoRequest* request,
                       ::echo::EchoResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(EchoService_Stub);
};


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// EchoRequest

// repeated int32 data = 1;
inline int EchoRequest::_internal_data_size() const {
  return data_.size();
}
inline int EchoRequest::data_size() const {
  return _internal_data_size();
}
inline void EchoRequest::clear_data() {
  data_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::int32 EchoRequest::_internal_data(int index) const {
  return data_.Get(index);
}
inline ::PROTOBUF_NAMESPACE_ID::int32 EchoRequest::data(int index) const {
  // @@protoc_insertion_point(field_get:echo.EchoRequest.data)
  return _internal_data(index);
}
inline void EchoRequest::set_data(int index, ::PROTOBUF_NAMESPACE_ID::int32 value) {
  data_.Set(index, value);
  // @@protoc_insertion_point(field_set:echo.EchoRequest.data)
}
inline void EchoRequest::_internal_add_data(::PROTOBUF_NAMESPACE_ID::int32 value) {
  data_.Add(value);
}
inline void EchoRequest::add_data(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_add_data(value);
  // @@protoc_insertion_point(field_add:echo.EchoRequest.data)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
EchoRequest::_internal_data() const {
  return data_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
EchoRequest::data() const {
  // @@protoc_insertion_point(field_list:echo.EchoRequest.data)
  return _internal_data();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
EchoRequest::_internal_mutable_data() {
  return &data_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
EchoRequest::mutable_data() {
  // @@protoc_insertion_point(field_mutable_list:echo.EchoRequest.data)
  return _internal_mutable_data();
}

// -------------------------------------------------------------------

// EchoResponse

// repeated int32 sorted_data = 1;
inline int EchoResponse::_internal_sorted_data_size() const {
  return sorted_data_.size();
}
inline int EchoResponse::sorted_data_size() const {
  return _internal_sorted_data_size();
}
inline void EchoResponse::clear_sorted_data() {
  sorted_data_.Clear();
}
inline ::PROTOBUF_NAMESPACE_ID::int32 EchoResponse::_internal_sorted_data(int index) const {
  return sorted_data_.Get(index);
}
inline ::PROTOBUF_NAMESPACE_ID::int32 EchoResponse::sorted_data(int index) const {
  // @@protoc_insertion_point(field_get:echo.EchoResponse.sorted_data)
  return _internal_sorted_data(index);
}
inline void EchoResponse::set_sorted_data(int index, ::PROTOBUF_NAMESPACE_ID::int32 value) {
  sorted_data_.Set(index, value);
  // @@protoc_insertion_point(field_set:echo.EchoResponse.sorted_data)
}
inline void EchoResponse::_internal_add_sorted_data(::PROTOBUF_NAMESPACE_ID::int32 value) {
  sorted_data_.Add(value);
}
inline void EchoResponse::add_sorted_data(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_add_sorted_data(value);
  // @@protoc_insertion_point(field_add:echo.EchoResponse.sorted_data)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
EchoResponse::_internal_sorted_data() const {
  return sorted_data_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >&
EchoResponse::sorted_data() const {
  // @@protoc_insertion_point(field_list:echo.EchoResponse.sorted_data)
  return _internal_sorted_data();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
EchoResponse::_internal_mutable_sorted_data() {
  return &sorted_data_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< ::PROTOBUF_NAMESPACE_ID::int32 >*
EchoResponse::mutable_sorted_data() {
  // @@protoc_insertion_point(field_mutable_list:echo.EchoResponse.sorted_data)
  return _internal_mutable_sorted_data();
}

// int32 sum = 2;
inline void EchoResponse::clear_sum() {
  sum_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 EchoResponse::_internal_sum() const {
  return sum_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 EchoResponse::sum() const {
  // @@protoc_insertion_point(field_get:echo.EchoResponse.sum)
  return _internal_sum();
}
inline void EchoResponse::_internal_set_sum(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  sum_ = value;
}
inline void EchoResponse::set_sum(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_sum(value);
  // @@protoc_insertion_point(field_set:echo.EchoResponse.sum)
}

// int32 index = 3;
inline void EchoResponse::clear_index() {
  index_ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 EchoResponse::_internal_index() const {
  return index_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 EchoResponse::index() const {
  // @@protoc_insertion_point(field_get:echo.EchoResponse.index)
  return _internal_index();
}
inline void EchoResponse::_internal_set_index(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  index_ = value;
}
inline void EchoResponse::set_index(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_index(value);
  // @@protoc_insertion_point(field_set:echo.EchoResponse.index)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace echo

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_echo_2eproto
