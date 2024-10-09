flowchart TD
    A[Khởi tạo] --> B{Danh sách mở rỗng hoặc tìm thấy đích?}
    B -->|Không| C[Chọn nút có f thấp nhất từ danh sách mở]
    C --> D[Di chuyển nút này từ danh sách mở sang danh sách đóng]
    D --> E{Nút hiện tại là đích?}
    E -->|Có| F[Kết thúc, truy vết đường đi]
    E -->|Không| G[Kiểm tra các nút kề]
    G --> H{Nút kề nằm trong danh sách đóng?}
    H -->|Có| I[Bỏ qua nút kề]
    H -->|Không| J{Nút kề nằm trong danh sách mở?}
    J -->|Không| K[Thêm nút kề vào danh sách mở, tính f, g, h]
    J -->|Có| L{Đường đi mới tốt hơn?}
    L -->|Có| M[Cập nhật f, g, h, đặt nút hiện tại làm cha của nút kề]
    L -->|Không| N[Bỏ qua nút kề]
    I --> B
    K --> B
    M --> B
    N --> B
    B -->|Có| O[Kết luận không có đường đi]
