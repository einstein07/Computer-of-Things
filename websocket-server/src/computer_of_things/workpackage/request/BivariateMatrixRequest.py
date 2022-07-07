# automatically generated by the FlatBuffers compiler, do not modify

# namespace: request

import flatbuffers

class BivariateMatrixRequest(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAsBivariateMatrixRequest(cls, buf, offset):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = BivariateMatrixRequest()
        x.Init(buf, n + offset)
        return x

    # BivariateMatrixRequest
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # BivariateMatrixRequest
    def AType(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Uint8Flags, o + self._tab.Pos)
        return 0

    # BivariateMatrixRequest
    def A(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            from flatbuffers.table import Table
            obj = Table(bytearray(), 0)
            self._tab.Union(obj, o)
            return obj
        return None

    # BivariateMatrixRequest
    def BType(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Uint8Flags, o + self._tab.Pos)
        return 0

    # BivariateMatrixRequest
    def B(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            from flatbuffers.table import Table
            obj = Table(bytearray(), 0)
            self._tab.Union(obj, o)
            return obj
        return None

def BivariateMatrixRequestStart(builder): builder.StartObject(4)
def BivariateMatrixRequestAddAType(builder, aType): builder.PrependUint8Slot(0, aType, 0)
def BivariateMatrixRequestAddA(builder, a): builder.PrependUOffsetTRelativeSlot(1, flatbuffers.number_types.UOffsetTFlags.py_type(a), 0)
def BivariateMatrixRequestAddBType(builder, bType): builder.PrependUint8Slot(2, bType, 0)
def BivariateMatrixRequestAddB(builder, b): builder.PrependUOffsetTRelativeSlot(3, flatbuffers.number_types.UOffsetTFlags.py_type(b), 0)
def BivariateMatrixRequestEnd(builder): return builder.EndObject()
