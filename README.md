# purple_clocks


Summarize the project and what problem it was solving.
-This program is a simple clock application written in C++. It allows the user to interact with the clock by setting the time, adding seconds, minutes, or hours to the 
current time, and displaying the time in both 12-hour and 24-hour formats.

What did you do particularly well?
-This program handles platform Compatibility particularly well. The program includes platform-specific code to handle console color changes. It detects whether the program is running on Windows or another platform and adjusts the code accordingly, allowing consistent behavior across different operating systems.

Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
-One thing this program could benefit from is more robust input valadation, to handle cases where a user enters a non-numeric or other unaccepted values.

Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
-The most challenging part was figuring out how to change the color of the text and make it cross-platform. Although it wasn't a required aspect of the project, I wanted to challenge myself. Whenever I encounter difficulties, I can always rely on my friend who graduated with a bachelor's degree in software engineering last year. Additionally, Google is a valuable resource that I frequently turn to when I need assistance.

What skills from this project will be particularly transferable to other projects or course work?
-One skill I learned that is transferable to future projects is the use of the preprocessor directive #ifdef _WIN32. The #ifdef _WIN32 directive allows the code to have platform-specific code blocks that are included or excluded based on whether the code is being compiled for a Windows platform or another platform. This skill is useful when developing cross-platform applications or dealing with platform-specific features.

How did you make this program maintainable, readable, and adaptable?
-The code is reasonably organized into classes and functions, making it easier to understand and modify specific components.
-Each function has a clear purpose, such as setting the time, adding seconds/minutes/hours, displaying the time, and handling user input.
-The code includes comments that provide explanations for certain sections, aiding in understanding and maintenance.
