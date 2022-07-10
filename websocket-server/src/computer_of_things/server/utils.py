import flatbuffers
import random

# our workpackage Python code
from ..workpackage.common import Matrix2D
from ..workpackage.OperationRequest import OperationRequest, OperationRequestAddId, OperationRequestAddOpType, OperationRequestAddRequest, OperationRequestAddRequestType, OperationRequestEnd, OperationRequestStart
from ..workpackage.Operation import Operation
from ..workpackage.request import Request
from ..workpackage.request import BivariateMatrixRequest

def addRandomMatrix2D(builder: flatbuffers.Builder, n_rows: int, n_cols: int) -> int:
    """
    Adds a random 2D matrix to a flat buffer builder, with elements of values between 0 and 1, and returns the offset in the buffer
    """

    num_elems = n_rows*n_cols
    
    # we first create the "elements" vector
    Matrix2D.Matrix2DStartElementsVector(builder, n_rows*n_cols)
    for e in range(0, num_elems):
        builder.PrependFloat64(random.random())
    
    elems = builder.EndVector()
    
    # then create final 2D matrix
    Matrix2D.Matrix2DStart(builder)
    Matrix2D.Matrix2DAddNRows(builder, n_rows)
    Matrix2D.Matrix2DAddNCols(builder, n_cols)
    Matrix2D.Matrix2DAddElements(builder, elems)
    
    return Matrix2D.Matrix2DEnd(builder)


def createMatrixMultiplyRequest(n_rows: int, n_cols: int):
    """
    Creates a multiplication request for two matrices with the given size.
    """

    # create a flatbuffer builder that will hold the final message
    builder = flatbuffers.Builder(1024)

    # since we are building in reverse, we want to create the BivariateMatrixRequest first
    matrix_a = addRandomMatrix2D(builder, n_rows, n_cols)
    matrix_b = addRandomMatrix2D(builder, n_rows, n_cols)
    BivariateMatrixRequest.BivariateMatrixRequestStart(builder)
    BivariateMatrixRequest.BivariateMatrixRequestAddA(builder, matrix_a)
    BivariateMatrixRequest.BivariateMatrixRequestAddB(builder, matrix_b)
    bivar_request = BivariateMatrixRequest.BivariateMatrixRequestEnd(builder)

    # we start building the OperationRequest message
    OperationRequestStart(builder)
    OperationRequestAddId(builder, 1)
    OperationRequestAddOpType(builder, Operation.MULTIPLY)
    # the "request" field is a union, so we need to specify the union type and the union data
    OperationRequestAddRequestType(builder, Request.Request().BivariateMatrixRequest)
    OperationRequestAddRequest(builder, bivar_request)
    
    op_request = OperationRequestEnd(builder)

    # instruct the builder that our message is complete
    builder.Finish(op_request)

    serialized_mesg = builder.Output()

    return serialized_mesg


def createAddRequest():
    pass

def createSubtractRequest():
    pass
