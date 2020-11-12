<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="html" encoding="UTF-8"/>
  <xsl:template match="/">

<html>
<head>
</head>
<body>

<!-- Правила преобразования XML-документа в HTML -->

    <xsl:value-of select="Название"/>
    <xsl:value-of select="Столица"/>

<!-- ........................................... --> 

</body>
</html>

  </xsl:template>
</xsl:stylesheet>