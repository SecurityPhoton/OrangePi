import setuptools

with open("README.md", "r") as fh:
    long_description = fh.read()

setuptools.setup(
    name="mfrc522",
    version="0.0.8",
    author="Pi My Life Up",
    author_email="support@pimylifeup.com",
    description="A library to integrate the MFRC522 RFID readers with the Raspberry Pi and OrangePI",
    long_description=long_description,
    long_description_content_type="text/markdown",
    url="https://github.com/SecurityPhoton/OrangePi",
    packages=setuptools.find_packages(),
    classifiers=[
        "Programming Language :: Python :: 2.7",
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: GNU Lesser General Public License v3 or later (LGPLv3+)",
        "Operating System :: POSIX :: Linux",
        'Topic :: System :: Hardware',
    ],
)
