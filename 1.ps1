1..254 | ForEach-Object {
    $ip = "192.168.1.$_"
    if (Test-Connection -ComputerName $ip -Count 1 -Quiet) {
        try {
            $hostname = ([System.Net.Dns]::GetHostEntry($ip)).HostName
        } catch {
            $hostname = "无法解析"
        }
        Write-Output "$ip : $hostname"
    }
}
