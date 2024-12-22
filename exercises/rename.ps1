# Get all chapter directories matching the pattern chapter0[0-9]
$chapterDirs = Get-ChildItem -Directory | Where-Object { $_.Name -match '^chapter0\d$' }

foreach ($chapter in $chapterDirs) {
    $newName = $chapter.Name -replace '^chapter(0\d)$', 'ch$1'
    Rename-Item -Path $chapter.FullName -NewName $newName -Verbose
}