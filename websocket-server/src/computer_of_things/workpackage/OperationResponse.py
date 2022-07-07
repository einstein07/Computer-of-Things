# automatically generated by the FlatBuffers compiler, do not modify

# namespace: workpackage

import flatbuffers

class OperationResponse(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAsOperationResponse(cls, buf, offset):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = OperationResponse()
        x.Init(buf, n + offset)
        return x

    # OperationResponse
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # OperationResponse
    def Id(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int64Flags, o + self._tab.Pos)
        return 0

    # OperationResponse
    def OpType(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int8Flags, o + self._tab.Pos)
        return 0

    # OperationResponse
    def ResponseType(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Uint8Flags, o + self._tab.Pos)
        return 0

    # OperationResponse
    def Response(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            from flatbuffers.table import Table
            obj = Table(bytearray(), 0)
            self._tab.Union(obj, o)
            return obj
        return None

def OperationResponseStart(builder): builder.StartObject(4)
def OperationResponseAddId(builder, id): builder.PrependInt64Slot(0, id, 0)
def OperationResponseAddOpType(builder, opType): builder.PrependInt8Slot(1, opType, 0)
def OperationResponseAddResponseType(builder, responseType): builder.PrependUint8Slot(2, responseType, 0)
def OperationResponseAddResponse(builder, response): builder.PrependUOffsetTRelativeSlot(3, flatbuffers.number_types.UOffsetTFlags.py_type(response), 0)
def OperationResponseEnd(builder): return builder.EndObject()
