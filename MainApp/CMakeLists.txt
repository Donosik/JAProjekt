cmake_minimum_required(VERSION 3.22)
project(MainApp)

set(CMAKE_CXX_STANDARD 23)

add_executable(MainApp main.cpp Application.cpp Application.h Button.cpp Button.h GroupRadioButton.cpp GroupRadioButton.h IImageObserver.h ImageButton.cpp ImageButton.h ImageLoader.cpp ImageLoader.h ImageObservable.cpp ImageObservable.h IStatusObserver.cpp IStatusObserver.h ITimeObserver.h IView.h LibraryWrapper.cpp LibraryWrapper.h RadioButton.cpp RadioButton.h ResultImage.cpp ResultImage.h ShowTime.cpp ShowTime.h Slider.cpp Slider.h Status.h StatusObservable.cpp StatusObservable.h TimeObservable.cpp TimeObservable.h WindowData.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include)
target_link_libraries(MainApp sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
