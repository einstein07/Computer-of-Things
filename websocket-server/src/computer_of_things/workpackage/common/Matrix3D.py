# automatically generated by the FlatBuffers compiler, do not modify

# namespace: common

import flatbuffers

class Matrix3D(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAsMatrix3D(cls, buf, offset):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = Matrix3D()
        x.Init(buf, n + offset)
        return x

    # Matrix3D
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # Matrix3D
    def NumRows(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

    # Matrix3D
    def NumCols(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(6))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

    # Matrix3D
    def NumPages(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(8))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Int32Flags, o + self._tab.Pos)
        return 0

    # Matrix3D
    def Elements(self, j):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            a = self._tab.Vector(o)
            return self._tab.Get(flatbuffers.number_types.Float32Flags, a + flatbuffers.number_types.UOffsetTFlags.py_type(j * 4))
        return 0

    # Matrix3D
    def ElementsAsNumpy(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            return self._tab.GetVectorAsNumpy(flatbuffers.number_types.Float32Flags, o)
        return 0

    # Matrix3D
    def ElementsLength(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(10))
        if o != 0:
            return self._tab.VectorLen(o)
        return 0

def Matrix3DStart(builder): builder.StartObject(4)
def Matrix3DAddNumRows(builder, numRows): builder.PrependInt32Slot(0, numRows, 0)
def Matrix3DAddNumCols(builder, numCols): builder.PrependInt32Slot(1, numCols, 0)
def Matrix3DAddNumPages(builder, numPages): builder.PrependInt32Slot(2, numPages, 0)
def Matrix3DAddElements(builder, elements): builder.PrependUOffsetTRelativeSlot(3, flatbuffers.number_types.UOffsetTFlags.py_type(elements), 0)
def Matrix3DStartElementsVector(builder, numElems): return builder.StartVector(4, numElems, 4)
def Matrix3DEnd(builder): return builder.EndObject()
