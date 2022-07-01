<?php
  $head1 = "<!DOCTYPE html>\n<html lang=\"en\">\n<head>\n  <meta charset=\"UTF-8\">\n  <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">\n  <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n  <title>";
  $head2 = "</title>\n  <link rel=\"stylesheet\" href=\"./styles.css\"></link>\n</head>\n<body>\n";
  $tail = "</body>\n</html>";

  function mklink($dest,$txt)
  {
    return "<a href=\"$dst\">$txt</a>\n";
  }

  function mkimg($imglnk)
  {
    return "<img src= \"$imglnk\"></img>\n";
  }

  function listels($els)
  {
    $lis = '';
    foreach($els as $el)
      $lis = $lis."<li>$el</li>\n";
    return $lis;
  }

  function ollist($els)
  {
    return "<ol>\n".listels($els)."</ol>\n";
  }

  function ullist($els)
  {
    return "<ul>\n".listels($els)."</ul>\n";
  }

?>