## Thư mục gồm có:
-   1 file pwd_cracking.pdf
-   1 file pwd_cracking.cpp( file khôi phục mật khẩu)
-   1 file pwd_cracking_gen_board.cpp(file sinh dữ liệu)
### Lưu ý quan trọng:
-   Trong phần đánh giá thời gian chạy và bộ nhớ sử dụng dựa trên dữ liệu thực tế, do có 1 số sai sót trong quá trình lấy kết quả đầu ra dẫn đến việc kết quả đo trong file bị sai, mong mọi người thông cảm T_T và không nên sử dụng những kết quả dữ liệu đó. Sau đây mình xin cập nhật lại kết quả đo được:
    -   Test 1 : 
        Time : < 0.00s, Memory : ~ 0 KiB
    -   Test 2 :
        Time : < 0.00s, Memory : ~ 0 KiB
    -   Test 3 :
        Time : < 0.61s, Memory : ~ 34844 KiB
    -   Test 4 :
        Time : < 54.49s, Memory : ~ 1312800 KiB
    -   Test 5 :
        Time : ERROR , Memory : ERROR
    -   Test 6 :
        Time : < 0.63s, Memory : ~ 34844 KiB
-   Mình xin được phép giải thích 1 số điều về kết quả trên:
    -   Ở test case số 1 và số 2, do thời gian chạy được nhỏ hơn 0.01s và cũng như lượng bộ nhớ xài hoàn toàn ít, nên sẽ có 1 số bản hiểu lầm kết quả thành chạy trong 0s và không sử dụng memory, điều này hoàn toàn sai nha!!!
    -   Test case số 5 có ghi là ERROR, thì lí do giải thích cho vấn đề này là vì lượng memory của mình được sử dụng vượt quá yêu cầu mà máy chấm cho phép, nên xảy ra lỗi và không đo được thời gian chạy của test này. Có thể thấy đây vẫn chưa phải là thuật toán tối ưu nhất do vấn đề hạn chế về memory, thế nên mình khuyến khích bạn nên tham khảo Schroeppel and Shamir's Algorithm để biết thêm cách tối ưu memory( cũng 1 phần do cách giải thích của mình chưa rõ trong tài liệu T_T)
