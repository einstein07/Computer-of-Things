# automatically generated by the FlatBuffers compiler, do not modify

# namespace: response

import flatbuffers

class ScalarResponse(object):
    __slots__ = ['_tab']

    @classmethod
    def GetRootAsScalarResponse(cls, buf, offset):
        n = flatbuffers.encode.Get(flatbuffers.packer.uoffset, buf, offset)
        x = ScalarResponse()
        x.Init(buf, n + offset)
        return x

    # ScalarResponse
    def Init(self, buf, pos):
        self._tab = flatbuffers.table.Table(buf, pos)

    # ScalarResponse
    def Response(self):
        o = flatbuffers.number_types.UOffsetTFlags.py_type(self._tab.Offset(4))
        if o != 0:
            return self._tab.Get(flatbuffers.number_types.Float32Flags, o + self._tab.Pos)
        return 0.0

def ScalarResponseStart(builder): builder.StartObject(1)
def ScalarResponseAddResponse(builder, response): builder.PrependFloat32Slot(0, response, 0.0)
def ScalarResponseEnd(builder): return builder.EndObject()
