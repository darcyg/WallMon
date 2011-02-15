// Generated by the protocol buffer compiler.  DO NOT EDIT!

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "Protocol.pb.h"
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace {

const ::google::protobuf::Descriptor* DataPacket_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DataPacket_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_Protocol_2eproto() {
  protobuf_AddDesc_Protocol_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "Protocol.proto");
  GOOGLE_CHECK(file != NULL);
  DataPacket_descriptor_ = file->message_type(0);
  static const int DataPacket_offsets_[5] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataPacket, numthreads_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataPacket, usertime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataPacket, systemtime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataPacket, usercpuload_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataPacket, systemcpuload_),
  };
  DataPacket_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      DataPacket_descriptor_,
      DataPacket::default_instance_,
      DataPacket_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataPacket, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DataPacket, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(DataPacket));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_Protocol_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    DataPacket_descriptor_, &DataPacket::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_Protocol_2eproto() {
  delete DataPacket::default_instance_;
  delete DataPacket_reflection_;
}

void protobuf_AddDesc_Protocol_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\016Protocol.proto\"r\n\nDataPacket\022\022\n\nnumThr"
    "eads\030\001 \002(\r\022\020\n\010userTime\030\002 \002(\001\022\022\n\nsystemTi"
    "me\030\003 \002(\001\022\023\n\013userCpuLoad\030\004 \002(\001\022\025\n\rsystemC"
    "puLoad\030\005 \002(\001", 132);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "Protocol.proto", &protobuf_RegisterTypes);
  DataPacket::default_instance_ = new DataPacket();
  DataPacket::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_Protocol_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_Protocol_2eproto {
  StaticDescriptorInitializer_Protocol_2eproto() {
    protobuf_AddDesc_Protocol_2eproto();
  }
} static_descriptor_initializer_Protocol_2eproto_;


// ===================================================================

#ifndef _MSC_VER
const int DataPacket::kNumThreadsFieldNumber;
const int DataPacket::kUserTimeFieldNumber;
const int DataPacket::kSystemTimeFieldNumber;
const int DataPacket::kUserCpuLoadFieldNumber;
const int DataPacket::kSystemCpuLoadFieldNumber;
#endif  // !_MSC_VER

DataPacket::DataPacket()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void DataPacket::InitAsDefaultInstance() {
}

DataPacket::DataPacket(const DataPacket& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void DataPacket::SharedCtor() {
  _cached_size_ = 0;
  numthreads_ = 0u;
  usertime_ = 0;
  systemtime_ = 0;
  usercpuload_ = 0;
  systemcpuload_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

DataPacket::~DataPacket() {
  SharedDtor();
}

void DataPacket::SharedDtor() {
  if (this != default_instance_) {
  }
}

void DataPacket::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* DataPacket::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DataPacket_descriptor_;
}

const DataPacket& DataPacket::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_Protocol_2eproto();  return *default_instance_;
}

DataPacket* DataPacket::default_instance_ = NULL;

DataPacket* DataPacket::New() const {
  return new DataPacket;
}

void DataPacket::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    numthreads_ = 0u;
    usertime_ = 0;
    systemtime_ = 0;
    usercpuload_ = 0;
    systemcpuload_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool DataPacket::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required uint32 numThreads = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint32, ::google::protobuf::internal::WireFormatLite::TYPE_UINT32>(
                 input, &numthreads_)));
          _set_bit(0);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(17)) goto parse_userTime;
        break;
      }
      
      // required double userTime = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_userTime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &usertime_)));
          _set_bit(1);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(25)) goto parse_systemTime;
        break;
      }
      
      // required double systemTime = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_systemTime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &systemtime_)));
          _set_bit(2);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(33)) goto parse_userCpuLoad;
        break;
      }
      
      // required double userCpuLoad = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_userCpuLoad:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &usercpuload_)));
          _set_bit(3);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(41)) goto parse_systemCpuLoad;
        break;
      }
      
      // required double systemCpuLoad = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_FIXED64) {
         parse_systemCpuLoad:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &systemcpuload_)));
          _set_bit(4);
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }
      
      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void DataPacket::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // required uint32 numThreads = 1;
  if (_has_bit(0)) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt32(1, this->numthreads(), output);
  }
  
  // required double userTime = 2;
  if (_has_bit(1)) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(2, this->usertime(), output);
  }
  
  // required double systemTime = 3;
  if (_has_bit(2)) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(3, this->systemtime(), output);
  }
  
  // required double userCpuLoad = 4;
  if (_has_bit(3)) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(4, this->usercpuload(), output);
  }
  
  // required double systemCpuLoad = 5;
  if (_has_bit(4)) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(5, this->systemcpuload(), output);
  }
  
  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* DataPacket::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // required uint32 numThreads = 1;
  if (_has_bit(0)) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt32ToArray(1, this->numthreads(), target);
  }
  
  // required double userTime = 2;
  if (_has_bit(1)) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(2, this->usertime(), target);
  }
  
  // required double systemTime = 3;
  if (_has_bit(2)) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(3, this->systemtime(), target);
  }
  
  // required double userCpuLoad = 4;
  if (_has_bit(3)) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(4, this->usercpuload(), target);
  }
  
  // required double systemCpuLoad = 5;
  if (_has_bit(4)) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(5, this->systemcpuload(), target);
  }
  
  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int DataPacket::ByteSize() const {
  int total_size = 0;
  
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required uint32 numThreads = 1;
    if (has_numthreads()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt32Size(
          this->numthreads());
    }
    
    // required double userTime = 2;
    if (has_usertime()) {
      total_size += 1 + 8;
    }
    
    // required double systemTime = 3;
    if (has_systemtime()) {
      total_size += 1 + 8;
    }
    
    // required double userCpuLoad = 4;
    if (has_usercpuload()) {
      total_size += 1 + 8;
    }
    
    // required double systemCpuLoad = 5;
    if (has_systemcpuload()) {
      total_size += 1 + 8;
    }
    
  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void DataPacket::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const DataPacket* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const DataPacket*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void DataPacket::MergeFrom(const DataPacket& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from._has_bit(0)) {
      set_numthreads(from.numthreads());
    }
    if (from._has_bit(1)) {
      set_usertime(from.usertime());
    }
    if (from._has_bit(2)) {
      set_systemtime(from.systemtime());
    }
    if (from._has_bit(3)) {
      set_usercpuload(from.usercpuload());
    }
    if (from._has_bit(4)) {
      set_systemcpuload(from.systemcpuload());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void DataPacket::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DataPacket::CopyFrom(const DataPacket& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DataPacket::IsInitialized() const {
  if ((_has_bits_[0] & 0x0000001f) != 0x0000001f) return false;
  
  return true;
}

void DataPacket::Swap(DataPacket* other) {
  if (other != this) {
    std::swap(numthreads_, other->numthreads_);
    std::swap(usertime_, other->usertime_);
    std::swap(systemtime_, other->systemtime_);
    std::swap(usercpuload_, other->usercpuload_);
    std::swap(systemcpuload_, other->systemcpuload_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata DataPacket::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = DataPacket_descriptor_;
  metadata.reflection = DataPacket_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
