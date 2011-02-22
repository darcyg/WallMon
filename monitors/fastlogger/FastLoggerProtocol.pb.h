// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: FastLoggerProtocol.proto

#ifndef PROTOBUF_FastLoggerProtocol_2eproto__INCLUDED
#define PROTOBUF_FastLoggerProtocol_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2003000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_message_reflection.h>
// @@protoc_insertion_point(includes)

namespace FastLogger {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_FastLoggerProtocol_2eproto();
void protobuf_AssignDesc_FastLoggerProtocol_2eproto();
void protobuf_ShutdownFile_FastLoggerProtocol_2eproto();

class DataPacket;

// ===================================================================

class DataPacket : public ::google::protobuf::Message {
 public:
  DataPacket();
  virtual ~DataPacket();
  
  DataPacket(const DataPacket& from);
  
  inline DataPacket& operator=(const DataPacket& from) {
    CopyFrom(from);
    return *this;
  }
  
  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }
  
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }
  
  static const ::google::protobuf::Descriptor* descriptor();
  static const DataPacket& default_instance();
  
  void Swap(DataPacket* other);
  
  // implements Message ----------------------------------------------
  
  DataPacket* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const DataPacket& from);
  void MergeFrom(const DataPacket& from);
  void Clear();
  bool IsInitialized() const;
  
  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  
  ::google::protobuf::Metadata GetMetadata() const;
  
  // nested types ----------------------------------------------------
  
  // accessors -------------------------------------------------------
  
  // required bytes junk = 1;
  inline bool has_junk() const;
  inline void clear_junk();
  static const int kJunkFieldNumber = 1;
  inline const ::std::string& junk() const;
  inline void set_junk(const ::std::string& value);
  inline void set_junk(const char* value);
  inline void set_junk(const void* value, size_t size);
  inline ::std::string* mutable_junk();
  
  // @@protoc_insertion_point(class_scope:FastLogger.DataPacket)
 private:
  ::google::protobuf::UnknownFieldSet _unknown_fields_;
  mutable int _cached_size_;
  
  ::std::string* junk_;
  static const ::std::string _default_junk_;
  friend void  protobuf_AddDesc_FastLoggerProtocol_2eproto();
  friend void protobuf_AssignDesc_FastLoggerProtocol_2eproto();
  friend void protobuf_ShutdownFile_FastLoggerProtocol_2eproto();
  
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];
  
  // WHY DOES & HAVE LOWER PRECEDENCE THAN != !?
  inline bool _has_bit(int index) const {
    return (_has_bits_[index / 32] & (1u << (index % 32))) != 0;
  }
  inline void _set_bit(int index) {
    _has_bits_[index / 32] |= (1u << (index % 32));
  }
  inline void _clear_bit(int index) {
    _has_bits_[index / 32] &= ~(1u << (index % 32));
  }
  
  void InitAsDefaultInstance();
  static DataPacket* default_instance_;
};
// ===================================================================


// ===================================================================

// DataPacket

// required bytes junk = 1;
inline bool DataPacket::has_junk() const {
  return _has_bit(0);
}
inline void DataPacket::clear_junk() {
  if (junk_ != &_default_junk_) {
    junk_->clear();
  }
  _clear_bit(0);
}
inline const ::std::string& DataPacket::junk() const {
  return *junk_;
}
inline void DataPacket::set_junk(const ::std::string& value) {
  _set_bit(0);
  if (junk_ == &_default_junk_) {
    junk_ = new ::std::string;
  }
  junk_->assign(value);
}
inline void DataPacket::set_junk(const char* value) {
  _set_bit(0);
  if (junk_ == &_default_junk_) {
    junk_ = new ::std::string;
  }
  junk_->assign(value);
}
inline void DataPacket::set_junk(const void* value, size_t size) {
  _set_bit(0);
  if (junk_ == &_default_junk_) {
    junk_ = new ::std::string;
  }
  junk_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* DataPacket::mutable_junk() {
  _set_bit(0);
  if (junk_ == &_default_junk_) {
    junk_ = new ::std::string;
  }
  return junk_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace FastLogger

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_FastLoggerProtocol_2eproto__INCLUDED
