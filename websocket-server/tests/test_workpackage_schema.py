from venv import create
from computer_of_things.server.utils import createMatrixMultiplyRequest

def test_matrix_creation():
    # Create a builder

    mesg = createMatrixMultiplyRequest(2, 2)
    print(mesg)





    
    

