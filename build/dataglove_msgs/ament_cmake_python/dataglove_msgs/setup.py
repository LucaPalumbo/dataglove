from setuptools import find_packages
from setuptools import setup

setup(
    name='dataglove_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('dataglove_msgs', 'dataglove_msgs.*')),
)
