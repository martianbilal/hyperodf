// Code generated by protoc-gen-gogo. DO NOT EDIT.
// source: github.com/kata-containers/kata-containers/src/libs/protocols/protos/health.proto

package grpc

import (
	bytes "bytes"
	context "context"
	fmt "fmt"
	github_com_containerd_ttrpc "github.com/containerd/ttrpc"
	_ "github.com/gogo/protobuf/gogoproto"
	proto "github.com/gogo/protobuf/proto"
	io "io"
	math "math"
	math_bits "math/bits"
	reflect "reflect"
	strings "strings"
)

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// This is a compile-time assertion to ensure that this generated file
// is compatible with the proto package it is being compiled against.
// A compilation error at this line likely means your copy of the
// proto package needs to be updated.
const _ = proto.GoGoProtoPackageIsVersion3 // please upgrade the proto package

type HealthCheckResponse_ServingStatus int32

const (
	HealthCheckResponse_UNKNOWN     HealthCheckResponse_ServingStatus = 0
	HealthCheckResponse_SERVING     HealthCheckResponse_ServingStatus = 1
	HealthCheckResponse_NOT_SERVING HealthCheckResponse_ServingStatus = 2
)

var HealthCheckResponse_ServingStatus_name = map[int32]string{
	0: "UNKNOWN",
	1: "SERVING",
	2: "NOT_SERVING",
}

var HealthCheckResponse_ServingStatus_value = map[string]int32{
	"UNKNOWN":     0,
	"SERVING":     1,
	"NOT_SERVING": 2,
}

func (x HealthCheckResponse_ServingStatus) String() string {
	return proto.EnumName(HealthCheckResponse_ServingStatus_name, int32(x))
}

func (HealthCheckResponse_ServingStatus) EnumDescriptor() ([]byte, []int) {
	return fileDescriptor_6d1ebcee089b4b35, []int{1, 0}
}

type CheckRequest struct {
	Service              string   `protobuf:"bytes,1,opt,name=service,proto3" json:"service,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *CheckRequest) Reset()      { *m = CheckRequest{} }
func (*CheckRequest) ProtoMessage() {}
func (*CheckRequest) Descriptor() ([]byte, []int) {
	return fileDescriptor_6d1ebcee089b4b35, []int{0}
}
func (m *CheckRequest) XXX_Unmarshal(b []byte) error {
	return m.Unmarshal(b)
}
func (m *CheckRequest) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	if deterministic {
		return xxx_messageInfo_CheckRequest.Marshal(b, m, deterministic)
	} else {
		b = b[:cap(b)]
		n, err := m.MarshalToSizedBuffer(b)
		if err != nil {
			return nil, err
		}
		return b[:n], nil
	}
}
func (m *CheckRequest) XXX_Merge(src proto.Message) {
	xxx_messageInfo_CheckRequest.Merge(m, src)
}
func (m *CheckRequest) XXX_Size() int {
	return m.Size()
}
func (m *CheckRequest) XXX_DiscardUnknown() {
	xxx_messageInfo_CheckRequest.DiscardUnknown(m)
}

var xxx_messageInfo_CheckRequest proto.InternalMessageInfo

type HealthCheckResponse struct {
	Status               HealthCheckResponse_ServingStatus `protobuf:"varint,1,opt,name=status,proto3,enum=grpc.HealthCheckResponse_ServingStatus" json:"status,omitempty"`
	XXX_NoUnkeyedLiteral struct{}                          `json:"-"`
	XXX_unrecognized     []byte                            `json:"-"`
	XXX_sizecache        int32                             `json:"-"`
}

func (m *HealthCheckResponse) Reset()      { *m = HealthCheckResponse{} }
func (*HealthCheckResponse) ProtoMessage() {}
func (*HealthCheckResponse) Descriptor() ([]byte, []int) {
	return fileDescriptor_6d1ebcee089b4b35, []int{1}
}
func (m *HealthCheckResponse) XXX_Unmarshal(b []byte) error {
	return m.Unmarshal(b)
}
func (m *HealthCheckResponse) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	if deterministic {
		return xxx_messageInfo_HealthCheckResponse.Marshal(b, m, deterministic)
	} else {
		b = b[:cap(b)]
		n, err := m.MarshalToSizedBuffer(b)
		if err != nil {
			return nil, err
		}
		return b[:n], nil
	}
}
func (m *HealthCheckResponse) XXX_Merge(src proto.Message) {
	xxx_messageInfo_HealthCheckResponse.Merge(m, src)
}
func (m *HealthCheckResponse) XXX_Size() int {
	return m.Size()
}
func (m *HealthCheckResponse) XXX_DiscardUnknown() {
	xxx_messageInfo_HealthCheckResponse.DiscardUnknown(m)
}

var xxx_messageInfo_HealthCheckResponse proto.InternalMessageInfo

type VersionCheckResponse struct {
	GrpcVersion          string   `protobuf:"bytes,1,opt,name=grpc_version,json=grpcVersion,proto3" json:"grpc_version,omitempty"`
	AgentVersion         string   `protobuf:"bytes,2,opt,name=agent_version,json=agentVersion,proto3" json:"agent_version,omitempty"`
	XXX_NoUnkeyedLiteral struct{} `json:"-"`
	XXX_unrecognized     []byte   `json:"-"`
	XXX_sizecache        int32    `json:"-"`
}

func (m *VersionCheckResponse) Reset()      { *m = VersionCheckResponse{} }
func (*VersionCheckResponse) ProtoMessage() {}
func (*VersionCheckResponse) Descriptor() ([]byte, []int) {
	return fileDescriptor_6d1ebcee089b4b35, []int{2}
}
func (m *VersionCheckResponse) XXX_Unmarshal(b []byte) error {
	return m.Unmarshal(b)
}
func (m *VersionCheckResponse) XXX_Marshal(b []byte, deterministic bool) ([]byte, error) {
	if deterministic {
		return xxx_messageInfo_VersionCheckResponse.Marshal(b, m, deterministic)
	} else {
		b = b[:cap(b)]
		n, err := m.MarshalToSizedBuffer(b)
		if err != nil {
			return nil, err
		}
		return b[:n], nil
	}
}
func (m *VersionCheckResponse) XXX_Merge(src proto.Message) {
	xxx_messageInfo_VersionCheckResponse.Merge(m, src)
}
func (m *VersionCheckResponse) XXX_Size() int {
	return m.Size()
}
func (m *VersionCheckResponse) XXX_DiscardUnknown() {
	xxx_messageInfo_VersionCheckResponse.DiscardUnknown(m)
}

var xxx_messageInfo_VersionCheckResponse proto.InternalMessageInfo

func init() {
	proto.RegisterEnum("grpc.HealthCheckResponse_ServingStatus", HealthCheckResponse_ServingStatus_name, HealthCheckResponse_ServingStatus_value)
	proto.RegisterType((*CheckRequest)(nil), "grpc.CheckRequest")
	proto.RegisterType((*HealthCheckResponse)(nil), "grpc.HealthCheckResponse")
	proto.RegisterType((*VersionCheckResponse)(nil), "grpc.VersionCheckResponse")
}

func init() {
	proto.RegisterFile("github.com/kata-containers/kata-containers/src/libs/protocols/protos/health.proto", fileDescriptor_6d1ebcee089b4b35)
}

var fileDescriptor_6d1ebcee089b4b35 = []byte{
	// 396 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x94, 0x52, 0x31, 0x4f, 0xeb, 0x30,
	0x18, 0xac, 0xab, 0xf7, 0x5a, 0x3d, 0xb7, 0x7d, 0x54, 0x86, 0xa1, 0x74, 0xb0, 0x20, 0x0c, 0x74,
	0x21, 0x91, 0x8a, 0x84, 0x04, 0x0b, 0x12, 0x08, 0x01, 0x42, 0x4a, 0x45, 0x0a, 0x45, 0x62, 0x68,
	0x95, 0x44, 0x26, 0x89, 0xda, 0xc6, 0xc1, 0x76, 0xba, 0xb0, 0x30, 0x32, 0xf3, 0x2b, 0xf8, 0x09,
	0x8c, 0x8c, 0x1d, 0x19, 0x19, 0x69, 0x7e, 0x05, 0x23, 0xb2, 0x93, 0xa2, 0x56, 0x94, 0x81, 0xcd,
	0xf7, 0xdd, 0x5d, 0xee, 0xbb, 0xe8, 0x83, 0xe7, 0x5e, 0x20, 0xfc, 0xd8, 0xd1, 0x5d, 0x3a, 0x34,
	0xfa, 0xb6, 0xb0, 0xb7, 0x5c, 0x1a, 0x0a, 0x3b, 0x08, 0x09, 0xe3, 0xdf, 0x30, 0x67, 0xae, 0x31,
	0x08, 0x1c, 0x6e, 0x44, 0x8c, 0x0a, 0xea, 0xd2, 0x41, 0xf6, 0xe2, 0x86, 0x4f, 0xec, 0x81, 0xf0,
	0x75, 0x85, 0xd0, 0x1f, 0x8f, 0x45, 0x6e, 0x5d, 0xf3, 0xa8, 0x47, 0x53, 0xde, 0x89, 0x6f, 0x0c,
	0x89, 0x14, 0x50, 0xaf, 0x54, 0xa9, 0x35, 0x60, 0xf9, 0xd0, 0x27, 0x6e, 0xdf, 0x22, 0xb7, 0x31,
	0xe1, 0x02, 0xd5, 0x60, 0x91, 0x13, 0x36, 0x0a, 0x5c, 0x52, 0x03, 0x6b, 0xa0, 0xf1, 0xcf, 0x9a,
	0x42, 0xed, 0x11, 0xc0, 0xe5, 0x13, 0x15, 0x92, 0x19, 0x78, 0x44, 0x43, 0x4e, 0xd0, 0x3e, 0x2c,
	0x70, 0x61, 0x8b, 0x98, 0x2b, 0xc3, 0xff, 0xe6, 0xa6, 0x2e, 0xc3, 0xf5, 0x05, 0x52, 0xbd, 0x2d,
	0x3f, 0x15, 0x7a, 0x6d, 0x25, 0xb7, 0x32, 0x9b, 0xb6, 0x07, 0x2b, 0x73, 0x04, 0x2a, 0xc1, 0xe2,
	0xa5, 0x79, 0x66, 0xb6, 0xae, 0xcc, 0x6a, 0x4e, 0x82, 0xf6, 0x91, 0xd5, 0x39, 0x35, 0x8f, 0xab,
	0x00, 0x2d, 0xc1, 0x92, 0xd9, 0xba, 0xe8, 0x4d, 0x07, 0x79, 0xad, 0x0b, 0x57, 0x3a, 0x84, 0xf1,
	0x80, 0x86, 0xf3, 0x4b, 0xad, 0xc3, 0xb2, 0xdc, 0xa2, 0x37, 0x4a, 0xc9, 0xac, 0x4b, 0x49, 0xce,
	0x32, 0x3d, 0xda, 0x80, 0x15, 0xdb, 0x23, 0xa1, 0xf8, 0xd2, 0xe4, 0x95, 0xa6, 0xac, 0x86, 0x99,
	0xa8, 0x79, 0x07, 0x0b, 0x69, 0x11, 0xb4, 0x03, 0xff, 0xaa, 0x08, 0x84, 0xd2, 0x7e, 0xb3, 0x7f,
	0xad, 0xbe, 0xfa, 0x63, 0x67, 0xb4, 0x0b, 0x8b, 0xd3, 0xc4, 0x45, 0xce, 0x7a, 0x3a, 0x5b, 0x54,
	0xe2, 0xe0, 0x01, 0x8c, 0x27, 0x38, 0xf7, 0x36, 0xc1, 0xb9, 0x8f, 0x09, 0x06, 0xf7, 0x09, 0x06,
	0x4f, 0x09, 0x06, 0xcf, 0x09, 0x06, 0x2f, 0x09, 0x06, 0xe3, 0x04, 0x83, 0xd7, 0x04, 0x83, 0xf7,
	0x04, 0x83, 0xeb, 0xee, 0x2f, 0x6f, 0x88, 0xc5, 0xa1, 0x08, 0x86, 0xc4, 0x18, 0x05, 0x4c, 0xcc,
	0x50, 0x51, 0xdf, 0x33, 0x54, 0xff, 0x99, 0xfb, 0x92, 0xfb, 0x39, 0x05, 0x85, 0xb7, 0x3f, 0x03,
	0x00, 0x00, 0xff, 0xff, 0x79, 0xb1, 0x2c, 0xdf, 0xac, 0x02, 0x00, 0x00,
}

func (this *CheckRequest) Equal(that interface{}) bool {
	if that == nil {
		return this == nil
	}

	that1, ok := that.(*CheckRequest)
	if !ok {
		that2, ok := that.(CheckRequest)
		if ok {
			that1 = &that2
		} else {
			return false
		}
	}
	if that1 == nil {
		return this == nil
	} else if this == nil {
		return false
	}
	if this.Service != that1.Service {
		return false
	}
	if !bytes.Equal(this.XXX_unrecognized, that1.XXX_unrecognized) {
		return false
	}
	return true
}
func (this *HealthCheckResponse) Equal(that interface{}) bool {
	if that == nil {
		return this == nil
	}

	that1, ok := that.(*HealthCheckResponse)
	if !ok {
		that2, ok := that.(HealthCheckResponse)
		if ok {
			that1 = &that2
		} else {
			return false
		}
	}
	if that1 == nil {
		return this == nil
	} else if this == nil {
		return false
	}
	if this.Status != that1.Status {
		return false
	}
	if !bytes.Equal(this.XXX_unrecognized, that1.XXX_unrecognized) {
		return false
	}
	return true
}
func (this *VersionCheckResponse) Equal(that interface{}) bool {
	if that == nil {
		return this == nil
	}

	that1, ok := that.(*VersionCheckResponse)
	if !ok {
		that2, ok := that.(VersionCheckResponse)
		if ok {
			that1 = &that2
		} else {
			return false
		}
	}
	if that1 == nil {
		return this == nil
	} else if this == nil {
		return false
	}
	if this.GrpcVersion != that1.GrpcVersion {
		return false
	}
	if this.AgentVersion != that1.AgentVersion {
		return false
	}
	if !bytes.Equal(this.XXX_unrecognized, that1.XXX_unrecognized) {
		return false
	}
	return true
}
func (m *CheckRequest) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalToSizedBuffer(dAtA[:size])
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *CheckRequest) MarshalTo(dAtA []byte) (int, error) {
	size := m.Size()
	return m.MarshalToSizedBuffer(dAtA[:size])
}

func (m *CheckRequest) MarshalToSizedBuffer(dAtA []byte) (int, error) {
	i := len(dAtA)
	_ = i
	var l int
	_ = l
	if m.XXX_unrecognized != nil {
		i -= len(m.XXX_unrecognized)
		copy(dAtA[i:], m.XXX_unrecognized)
	}
	if len(m.Service) > 0 {
		i -= len(m.Service)
		copy(dAtA[i:], m.Service)
		i = encodeVarintHealth(dAtA, i, uint64(len(m.Service)))
		i--
		dAtA[i] = 0xa
	}
	return len(dAtA) - i, nil
}

func (m *HealthCheckResponse) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalToSizedBuffer(dAtA[:size])
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *HealthCheckResponse) MarshalTo(dAtA []byte) (int, error) {
	size := m.Size()
	return m.MarshalToSizedBuffer(dAtA[:size])
}

func (m *HealthCheckResponse) MarshalToSizedBuffer(dAtA []byte) (int, error) {
	i := len(dAtA)
	_ = i
	var l int
	_ = l
	if m.XXX_unrecognized != nil {
		i -= len(m.XXX_unrecognized)
		copy(dAtA[i:], m.XXX_unrecognized)
	}
	if m.Status != 0 {
		i = encodeVarintHealth(dAtA, i, uint64(m.Status))
		i--
		dAtA[i] = 0x8
	}
	return len(dAtA) - i, nil
}

func (m *VersionCheckResponse) Marshal() (dAtA []byte, err error) {
	size := m.Size()
	dAtA = make([]byte, size)
	n, err := m.MarshalToSizedBuffer(dAtA[:size])
	if err != nil {
		return nil, err
	}
	return dAtA[:n], nil
}

func (m *VersionCheckResponse) MarshalTo(dAtA []byte) (int, error) {
	size := m.Size()
	return m.MarshalToSizedBuffer(dAtA[:size])
}

func (m *VersionCheckResponse) MarshalToSizedBuffer(dAtA []byte) (int, error) {
	i := len(dAtA)
	_ = i
	var l int
	_ = l
	if m.XXX_unrecognized != nil {
		i -= len(m.XXX_unrecognized)
		copy(dAtA[i:], m.XXX_unrecognized)
	}
	if len(m.AgentVersion) > 0 {
		i -= len(m.AgentVersion)
		copy(dAtA[i:], m.AgentVersion)
		i = encodeVarintHealth(dAtA, i, uint64(len(m.AgentVersion)))
		i--
		dAtA[i] = 0x12
	}
	if len(m.GrpcVersion) > 0 {
		i -= len(m.GrpcVersion)
		copy(dAtA[i:], m.GrpcVersion)
		i = encodeVarintHealth(dAtA, i, uint64(len(m.GrpcVersion)))
		i--
		dAtA[i] = 0xa
	}
	return len(dAtA) - i, nil
}

func encodeVarintHealth(dAtA []byte, offset int, v uint64) int {
	offset -= sovHealth(v)
	base := offset
	for v >= 1<<7 {
		dAtA[offset] = uint8(v&0x7f | 0x80)
		v >>= 7
		offset++
	}
	dAtA[offset] = uint8(v)
	return base
}
func NewPopulatedCheckRequest(r randyHealth, easy bool) *CheckRequest {
	this := &CheckRequest{}
	this.Service = string(randStringHealth(r))
	if !easy && r.Intn(10) != 0 {
		this.XXX_unrecognized = randUnrecognizedHealth(r, 2)
	}
	return this
}

func NewPopulatedHealthCheckResponse(r randyHealth, easy bool) *HealthCheckResponse {
	this := &HealthCheckResponse{}
	this.Status = HealthCheckResponse_ServingStatus([]int32{0, 1, 2}[r.Intn(3)])
	if !easy && r.Intn(10) != 0 {
		this.XXX_unrecognized = randUnrecognizedHealth(r, 2)
	}
	return this
}

func NewPopulatedVersionCheckResponse(r randyHealth, easy bool) *VersionCheckResponse {
	this := &VersionCheckResponse{}
	this.GrpcVersion = string(randStringHealth(r))
	this.AgentVersion = string(randStringHealth(r))
	if !easy && r.Intn(10) != 0 {
		this.XXX_unrecognized = randUnrecognizedHealth(r, 3)
	}
	return this
}

type randyHealth interface {
	Float32() float32
	Float64() float64
	Int63() int64
	Int31() int32
	Uint32() uint32
	Intn(n int) int
}

func randUTF8RuneHealth(r randyHealth) rune {
	ru := r.Intn(62)
	if ru < 10 {
		return rune(ru + 48)
	} else if ru < 36 {
		return rune(ru + 55)
	}
	return rune(ru + 61)
}
func randStringHealth(r randyHealth) string {
	v1 := r.Intn(100)
	tmps := make([]rune, v1)
	for i := 0; i < v1; i++ {
		tmps[i] = randUTF8RuneHealth(r)
	}
	return string(tmps)
}
func randUnrecognizedHealth(r randyHealth, maxFieldNumber int) (dAtA []byte) {
	l := r.Intn(5)
	for i := 0; i < l; i++ {
		wire := r.Intn(4)
		if wire == 3 {
			wire = 5
		}
		fieldNumber := maxFieldNumber + r.Intn(100)
		dAtA = randFieldHealth(dAtA, r, fieldNumber, wire)
	}
	return dAtA
}
func randFieldHealth(dAtA []byte, r randyHealth, fieldNumber int, wire int) []byte {
	key := uint32(fieldNumber)<<3 | uint32(wire)
	switch wire {
	case 0:
		dAtA = encodeVarintPopulateHealth(dAtA, uint64(key))
		v2 := r.Int63()
		if r.Intn(2) == 0 {
			v2 *= -1
		}
		dAtA = encodeVarintPopulateHealth(dAtA, uint64(v2))
	case 1:
		dAtA = encodeVarintPopulateHealth(dAtA, uint64(key))
		dAtA = append(dAtA, byte(r.Intn(256)), byte(r.Intn(256)), byte(r.Intn(256)), byte(r.Intn(256)), byte(r.Intn(256)), byte(r.Intn(256)), byte(r.Intn(256)), byte(r.Intn(256)))
	case 2:
		dAtA = encodeVarintPopulateHealth(dAtA, uint64(key))
		ll := r.Intn(100)
		dAtA = encodeVarintPopulateHealth(dAtA, uint64(ll))
		for j := 0; j < ll; j++ {
			dAtA = append(dAtA, byte(r.Intn(256)))
		}
	default:
		dAtA = encodeVarintPopulateHealth(dAtA, uint64(key))
		dAtA = append(dAtA, byte(r.Intn(256)), byte(r.Intn(256)), byte(r.Intn(256)), byte(r.Intn(256)))
	}
	return dAtA
}
func encodeVarintPopulateHealth(dAtA []byte, v uint64) []byte {
	for v >= 1<<7 {
		dAtA = append(dAtA, uint8(uint64(v)&0x7f|0x80))
		v >>= 7
	}
	dAtA = append(dAtA, uint8(v))
	return dAtA
}
func (m *CheckRequest) Size() (n int) {
	if m == nil {
		return 0
	}
	var l int
	_ = l
	l = len(m.Service)
	if l > 0 {
		n += 1 + l + sovHealth(uint64(l))
	}
	if m.XXX_unrecognized != nil {
		n += len(m.XXX_unrecognized)
	}
	return n
}

func (m *HealthCheckResponse) Size() (n int) {
	if m == nil {
		return 0
	}
	var l int
	_ = l
	if m.Status != 0 {
		n += 1 + sovHealth(uint64(m.Status))
	}
	if m.XXX_unrecognized != nil {
		n += len(m.XXX_unrecognized)
	}
	return n
}

func (m *VersionCheckResponse) Size() (n int) {
	if m == nil {
		return 0
	}
	var l int
	_ = l
	l = len(m.GrpcVersion)
	if l > 0 {
		n += 1 + l + sovHealth(uint64(l))
	}
	l = len(m.AgentVersion)
	if l > 0 {
		n += 1 + l + sovHealth(uint64(l))
	}
	if m.XXX_unrecognized != nil {
		n += len(m.XXX_unrecognized)
	}
	return n
}

func sovHealth(x uint64) (n int) {
	return (math_bits.Len64(x|1) + 6) / 7
}
func sozHealth(x uint64) (n int) {
	return sovHealth(uint64((x << 1) ^ uint64((int64(x) >> 63))))
}
func (this *CheckRequest) String() string {
	if this == nil {
		return "nil"
	}
	s := strings.Join([]string{`&CheckRequest{`,
		`Service:` + fmt.Sprintf("%v", this.Service) + `,`,
		`XXX_unrecognized:` + fmt.Sprintf("%v", this.XXX_unrecognized) + `,`,
		`}`,
	}, "")
	return s
}
func (this *HealthCheckResponse) String() string {
	if this == nil {
		return "nil"
	}
	s := strings.Join([]string{`&HealthCheckResponse{`,
		`Status:` + fmt.Sprintf("%v", this.Status) + `,`,
		`XXX_unrecognized:` + fmt.Sprintf("%v", this.XXX_unrecognized) + `,`,
		`}`,
	}, "")
	return s
}
func (this *VersionCheckResponse) String() string {
	if this == nil {
		return "nil"
	}
	s := strings.Join([]string{`&VersionCheckResponse{`,
		`GrpcVersion:` + fmt.Sprintf("%v", this.GrpcVersion) + `,`,
		`AgentVersion:` + fmt.Sprintf("%v", this.AgentVersion) + `,`,
		`XXX_unrecognized:` + fmt.Sprintf("%v", this.XXX_unrecognized) + `,`,
		`}`,
	}, "")
	return s
}
func valueToStringHealth(v interface{}) string {
	rv := reflect.ValueOf(v)
	if rv.IsNil() {
		return "nil"
	}
	pv := reflect.Indirect(rv).Interface()
	return fmt.Sprintf("*%v", pv)
}

type HealthService interface {
	Check(ctx context.Context, req *CheckRequest) (*HealthCheckResponse, error)
	Version(ctx context.Context, req *CheckRequest) (*VersionCheckResponse, error)
}

func RegisterHealthService(srv *github_com_containerd_ttrpc.Server, svc HealthService) {
	srv.Register("grpc.Health", map[string]github_com_containerd_ttrpc.Method{
		"Check": func(ctx context.Context, unmarshal func(interface{}) error) (interface{}, error) {
			var req CheckRequest
			if err := unmarshal(&req); err != nil {
				return nil, err
			}
			return svc.Check(ctx, &req)
		},
		"Version": func(ctx context.Context, unmarshal func(interface{}) error) (interface{}, error) {
			var req CheckRequest
			if err := unmarshal(&req); err != nil {
				return nil, err
			}
			return svc.Version(ctx, &req)
		},
	})
}

type healthClient struct {
	client *github_com_containerd_ttrpc.Client
}

func NewHealthClient(client *github_com_containerd_ttrpc.Client) HealthService {
	return &healthClient{
		client: client,
	}
}

func (c *healthClient) Check(ctx context.Context, req *CheckRequest) (*HealthCheckResponse, error) {
	var resp HealthCheckResponse
	if err := c.client.Call(ctx, "grpc.Health", "Check", req, &resp); err != nil {
		return nil, err
	}
	return &resp, nil
}

func (c *healthClient) Version(ctx context.Context, req *CheckRequest) (*VersionCheckResponse, error) {
	var resp VersionCheckResponse
	if err := c.client.Call(ctx, "grpc.Health", "Version", req, &resp); err != nil {
		return nil, err
	}
	return &resp, nil
}
func (m *CheckRequest) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowHealth
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= uint64(b&0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: CheckRequest: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: CheckRequest: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field Service", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowHealth
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				stringLen |= uint64(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			intStringLen := int(stringLen)
			if intStringLen < 0 {
				return ErrInvalidLengthHealth
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthHealth
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.Service = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipHealth(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if (skippy < 0) || (iNdEx+skippy) < 0 {
				return ErrInvalidLengthHealth
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			m.XXX_unrecognized = append(m.XXX_unrecognized, dAtA[iNdEx:iNdEx+skippy]...)
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func (m *HealthCheckResponse) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowHealth
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= uint64(b&0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: HealthCheckResponse: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: HealthCheckResponse: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 0 {
				return fmt.Errorf("proto: wrong wireType = %d for field Status", wireType)
			}
			m.Status = 0
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowHealth
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				m.Status |= HealthCheckResponse_ServingStatus(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
		default:
			iNdEx = preIndex
			skippy, err := skipHealth(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if (skippy < 0) || (iNdEx+skippy) < 0 {
				return ErrInvalidLengthHealth
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			m.XXX_unrecognized = append(m.XXX_unrecognized, dAtA[iNdEx:iNdEx+skippy]...)
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func (m *VersionCheckResponse) Unmarshal(dAtA []byte) error {
	l := len(dAtA)
	iNdEx := 0
	for iNdEx < l {
		preIndex := iNdEx
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return ErrIntOverflowHealth
			}
			if iNdEx >= l {
				return io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= uint64(b&0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		fieldNum := int32(wire >> 3)
		wireType := int(wire & 0x7)
		if wireType == 4 {
			return fmt.Errorf("proto: VersionCheckResponse: wiretype end group for non-group")
		}
		if fieldNum <= 0 {
			return fmt.Errorf("proto: VersionCheckResponse: illegal tag %d (wire type %d)", fieldNum, wire)
		}
		switch fieldNum {
		case 1:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field GrpcVersion", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowHealth
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				stringLen |= uint64(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			intStringLen := int(stringLen)
			if intStringLen < 0 {
				return ErrInvalidLengthHealth
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthHealth
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.GrpcVersion = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		case 2:
			if wireType != 2 {
				return fmt.Errorf("proto: wrong wireType = %d for field AgentVersion", wireType)
			}
			var stringLen uint64
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return ErrIntOverflowHealth
				}
				if iNdEx >= l {
					return io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				stringLen |= uint64(b&0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			intStringLen := int(stringLen)
			if intStringLen < 0 {
				return ErrInvalidLengthHealth
			}
			postIndex := iNdEx + intStringLen
			if postIndex < 0 {
				return ErrInvalidLengthHealth
			}
			if postIndex > l {
				return io.ErrUnexpectedEOF
			}
			m.AgentVersion = string(dAtA[iNdEx:postIndex])
			iNdEx = postIndex
		default:
			iNdEx = preIndex
			skippy, err := skipHealth(dAtA[iNdEx:])
			if err != nil {
				return err
			}
			if (skippy < 0) || (iNdEx+skippy) < 0 {
				return ErrInvalidLengthHealth
			}
			if (iNdEx + skippy) > l {
				return io.ErrUnexpectedEOF
			}
			m.XXX_unrecognized = append(m.XXX_unrecognized, dAtA[iNdEx:iNdEx+skippy]...)
			iNdEx += skippy
		}
	}

	if iNdEx > l {
		return io.ErrUnexpectedEOF
	}
	return nil
}
func skipHealth(dAtA []byte) (n int, err error) {
	l := len(dAtA)
	iNdEx := 0
	depth := 0
	for iNdEx < l {
		var wire uint64
		for shift := uint(0); ; shift += 7 {
			if shift >= 64 {
				return 0, ErrIntOverflowHealth
			}
			if iNdEx >= l {
				return 0, io.ErrUnexpectedEOF
			}
			b := dAtA[iNdEx]
			iNdEx++
			wire |= (uint64(b) & 0x7F) << shift
			if b < 0x80 {
				break
			}
		}
		wireType := int(wire & 0x7)
		switch wireType {
		case 0:
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return 0, ErrIntOverflowHealth
				}
				if iNdEx >= l {
					return 0, io.ErrUnexpectedEOF
				}
				iNdEx++
				if dAtA[iNdEx-1] < 0x80 {
					break
				}
			}
		case 1:
			iNdEx += 8
		case 2:
			var length int
			for shift := uint(0); ; shift += 7 {
				if shift >= 64 {
					return 0, ErrIntOverflowHealth
				}
				if iNdEx >= l {
					return 0, io.ErrUnexpectedEOF
				}
				b := dAtA[iNdEx]
				iNdEx++
				length |= (int(b) & 0x7F) << shift
				if b < 0x80 {
					break
				}
			}
			if length < 0 {
				return 0, ErrInvalidLengthHealth
			}
			iNdEx += length
		case 3:
			depth++
		case 4:
			if depth == 0 {
				return 0, ErrUnexpectedEndOfGroupHealth
			}
			depth--
		case 5:
			iNdEx += 4
		default:
			return 0, fmt.Errorf("proto: illegal wireType %d", wireType)
		}
		if iNdEx < 0 {
			return 0, ErrInvalidLengthHealth
		}
		if depth == 0 {
			return iNdEx, nil
		}
	}
	return 0, io.ErrUnexpectedEOF
}

var (
	ErrInvalidLengthHealth        = fmt.Errorf("proto: negative length found during unmarshaling")
	ErrIntOverflowHealth          = fmt.Errorf("proto: integer overflow")
	ErrUnexpectedEndOfGroupHealth = fmt.Errorf("proto: unexpected end of group")
)
