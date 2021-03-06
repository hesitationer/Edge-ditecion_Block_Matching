#include <opencv2/opencv.hpp>	//画像読み込み


int write_frame(char date_directory[], char Inputiamge[], int max_x, int max_y, int image_xt,int image_yt){

	char result_image_name[128];
	printf("inputiamge=%s", Inputiamge);
	cv::Mat ImputImageR = cv::imread(Inputiamge);	//入力画像の読み込み．opencv

	cv::rectangle(ImputImageR, cv::Point(max_x-1, max_y-1), cv::Point(max_x+ image_xt +1, max_y+ image_yt +1), cv::Scalar(0, 0, 200), 1, 0);

	//画面表示
	std::string windowName = "frame_image";
	cv::namedWindow(windowName);
	cv::imshow(windowName, ImputImageR);

	//画像保存
	sprintf(result_image_name,"%sresult_image.bmp", date_directory);
	imwrite(result_image_name, ImputImageR);

	cv::waitKey(0);

	return 0;
}