try {
    # 获取当前目录
    $directoryPath = Get-Location

    # 提示用户输入要删除的文件格式
    $fileExtension = Read-Host "请输入要删除的文件格式 (例如 .txt)"

    # 检查输入是否以"."开头
    if (-not $fileExtension.StartsWith(".")) {
        Write-Output "文件格式必须以 . 开头。"
        exit
    }

    # 获取当前目录下的所有文件
    $files = Get-ChildItem -Path $directoryPath -File

    # 遍历文件列表并删除匹配指定格式的文件
    foreach ($file in $files) {
        if ($file.Extension -eq $fileExtension) {
            Remove-Item -Path $file.FullName -Force
            Write-Output "已删除: $($file.FullName)"
        }
    }

    Write-Output "所有 $fileExtension 文件已从 $directoryPath 删除。"
}
catch {
    Write-Output "执行过程中出现错误: $_"
}
