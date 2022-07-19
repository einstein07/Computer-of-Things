# automatically generated by the FlatBuffers compiler, do not modify

# namespace: workpackage

import flatbuffers

class WorkpackageRequest(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAsWorkpackageRequest(cls, buf, offset):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = WorkpackageRequest()
        x.Init(buf, n + offset)
        return x

    # WorkpackageRequest
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # WorkpackageRequest
    def Id(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int64Flags, o + self._tab.Pos)
        return 0

    # WorkpackageRequest
    def OpType(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Uint16Flags, o + self._tab.Pos)
        return 0

    # WorkpackageRequest
    def RequestType(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Uint8Flags, o + self._tab.Pos)
        return 0

    # WorkpackageRequest
    def Request(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            from flatbuffers.table import Table
            obj = Table(bytearray(), 0)
            self._tab.Union(obj, o)
            return obj
        return None

def WorkpackageRequestStart(builder): builder.StartObject(4)
def WorkpackageRequestAddId(builder, id): builder.PrependInt64Slot(0, id, 0)
def WorkpackageRequestAddOpType(builder, opType): builder.PrependUint16Slot(1, opType, 0)
def WorkpackageRequestAddRequestType(builder, requestType): builder.PrependUint8Slot(2, requestType, 0)
def WorkpackageRequestAddRequest(builder, request): builder.PrependUOffsetTRelativeSlot(3, flatbuffers.number_types.UOffsetTFlags.py_type(request), 0)
def WorkpackageRequestEnd(builder): return builder.EndObject()