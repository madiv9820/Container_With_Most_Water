import os, json, unittest
from typing import List
from timeout_decorator import timeout
from source.python.solution import pySolution

class test_pySolution(unittest.TestCase):
    def setUp(self):
        """
        🛠️ Setup method:
        - Loads test cases from JSON 📂
        - Initializes the solution instance 🧠
        """
        # 📍 Get the current directory of this test file
        currentDirectory = os.path.dirname(os.path.abspath(__file__))

        # 📄 Construct path to test_cases.json
        filePath = os.path.join(currentDirectory, 'cases/cases.json')

        # 📖 Read and load JSON test cases
        with open(filePath, mode="r", encoding="utf-8") as read_file:
            self.__testcases = json.load(read_file)

            # 🧠 Initialize solution class
            self.__solution = pySolution()

        return super().setUp()
    
    @timeout(1)  # ⏱️ Ensure each test runs within 1 second
    def test(self):
        """
        🧪 Main test runner:
        Iterates over all test cases and validates outputs ✅
        """
        for testcases in self.__testcases:

            # 🏷️ Extract test case details
            testname: str = testcases['title']
            height: List[int] = testcases['input']
            expectedOutput: int = testcases['output']

            # 🔍 Run each test as a subTest for better isolation
            with self.subTest(testname):

                # ⚙️ Call the solution method
                actualOutput: int = self.__solution.py_maxArea(
                    height=height
                )

                # ✅ Assert the result matches expected output
                self.assertEqual(actualOutput, expectedOutput)

# 🚀 Entry point to run tests
if __name__ == '__main__':
    unittest.main()